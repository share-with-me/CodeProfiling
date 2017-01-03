#!/usr/bin/env python

#
# Scan a binary for locations which can be protected using the following gadget
# crafting heuristics.
#   * Use any available existing gadgets
#   * Modify immediates belonging to
#       1) the last mov into eax before a ret (the return value)
#       2) arithmetic instructions which can be easily split up, i.e. add and sub
#   * Modify jump offsets and call addresses by moving the target code around
#   * Use gadgets with far returns where possible
# We do not consider the spurious instruction insertion heuristic, as it can 
# always be applied. We do not separately consider results for the "using add
# for memory operations" heuristic, but instead group those results with the
# modified immediates category.
#
# In each case, we first locate all possible locations where a heuristic can be
# applied. Then, we simulate application of the heuristic, and scan back to see
# how long the created gadgets are. In the end, we end up with a number saying
# what fraction of the program bytes can be protected by each heuristic.
#
# Requires Python 2.7+, distorm3 and objdump.
#

import sys
import subprocess
import pickle
import binascii
import distorm3 as distorm


MAX_GADGET_BYTES = 30                   # Max bytes per gadget
MAX_GADGET_INS   = 5                    # Max instrs per gadget
DISTORM_MODE     = distorm.Decode32Bits # 32-bit mode for distorm
IMMEDIATE_LEN    = 4                    # 32-bit immediates
OFFSET_LEN       = 4                    # 32-bit offsets

debug = True
brief = False


def build_text_section_hex_strings(opcodes_by_addr):
    # Build dictionary of text section hex strings, keyed by start address.
    # Each hex string is a consecutive byte sequence in the binary, so gadgets 
    #can be found using a simple string search.
    text_hex = {}
    buf = ""
    next_addr = -1
    start_addr = 0
    for (d_addr, d_opcode, d_mnemonic) in opcodes_by_addr:
        if d_addr != next_addr:
            if len(buf) > 0:
                text_hex[start_addr] = buf.lower()
                buf = ""
        if len(buf) == 0:
            start_addr = d_addr
        next_addr = d_addr + len(d_opcode)/2
        buf = buf + d_opcode

    # Add trailing hex string if any.
    if len(buf) > 0:
        text_hex[start_addr] = buf.lower()

    return text_hex


def find_returns(text_hex, scan_retf):
    start = 0
    found = []
    op_ret = "c3"
    if scan_retf:
        op_ret = "cb"
    while start != -1:
        start = text_hex.find(op_ret, start)
        if start != -1:
            if start % 2 == 0: # Must be at a whole byte boundary
                found.append(start)
            start = start + 1

    return found


def scan_gadgets(opcodes_by_addr, scan_retf = False):
    # Find gadgets in the text section hex strings using simple string matching.
    text_hex = build_text_section_hex_strings(opcodes_by_addr)
    gadgets = []
    for (addr, code) in text_hex.iteritems():
        returns = find_returns(code, scan_retf)
        for ret_off in returns:
            g_len = 2
            while g_len < MAX_GADGET_BYTES:
                g_base = ret_off - 2*(g_len - 1)
                g_hex = code[g_base:g_base + 2*g_len]
                g_len = g_len + 1

                disasm = distorm.Decode(0, binascii.unhexlify(g_hex), DISTORM_MODE);
                if len(disasm) < 2:
                    continue
                if len(disasm) > MAX_GADGET_INS:
                    continue
                last_ins = disasm[-1][2]
                if last_ins[0:3] != "RET": # This also captures RETF
                    continue
                contains_db = False
                mnem_list = ""
                for i in disasm:
                    mnem = i[2]
                    mnem_list = mnem_list + ",".join(mnem.split(", ")) + "\n"
                    if mnem[0:2] == "DB":
                        contains_db = True
                if contains_db:
                    continue
                gadgets.append((addr + g_base/2, len(g_hex)/2, g_hex, mnem_list))

    return gadgets


def is_rep_prefix(opcode):
    for rep in [ "rep" ]:
        if rep in opcode:
            return True
    return False


def is_arithmetic_logic(opcode):
    for al in [ "add", "sub" , "mul", "div", "or" , "xor", "and", "inc", \
                "dec", "not" , "shl", "shr", "adc", "sbb", "das", "aas", \
                "neg", "imul", "sal", "sar" ]:
        if al in opcode:
            return True
    return False


def is_memory(opcode):
    for mem in [ "mov"  , "lea", "xchg", "sahf", "lahf", "stos", "lods", "xlat", \
                 "bswap" ]:
        if mem in opcode:
            return True
    return False


def is_stack(opcode):
    for st in [ "push", "pop", "enter", "leave" ]:
        if st in opcode:
            return True
    return False


def is_control_flow(opcode):
    for cf in [ "call", "ret"   , "jmp"   , "jo"   , "jno"  , "jb"  , "jnae" , "jc"   , \
                "jnb" , "jae"   , "jnc"   , "jz"   , "je"   , "jnz" , "jne"  , "jbe"  , \
                "jna" , "jnbe"  , "ja"    , "js"   , "jns"  , "jp"  , "jpe"  , "jnp"  , \
                "jpo" , "jl"    , "jnge"  , "jnl"  , "jge"  , "jle" , "jng"  , "jnle" , \
                "jg"  , "loopnz", "loopne", "loopz", "loope", "loop", "jecxz", "jrcxz" ]:
        if cf in opcode:
            return True
    return False


def is_control_flow_conditional(opcode):
    for cond in [ "cmp", "test", "set", "cmov", "scas" , "cmc" , "clc", "stc", \
                  "cli", "sti" , "cld", "std" , "bound", "arpl", "cmpxchg" ]:
        if cond in opcode:
            return True
    return is_control_flow(opcode)


def is_system_io(opcode):
    for sys in [ "hlt" ]:
        if sys in opcode:
            return True
    return False


def is_nop(opcode):
    for nop in [ "nop" ]:
        if nop in opcode:
            return True
    return False


def split_opcode_from_operands(mnemonic):
    try:
        opcode, operands = mnemonic.split(None, 1)
        if is_rep_prefix(opcode):
            # Now get the "real" opcode
            opcode, operands = operands.split(None, 1)
        operands = [ op.strip() for op in operands.split(",") ]
    except:
        # Instruction without operands
        opcode = mnemonic.strip()
        operands = []
    return (opcode, operands)


def classify_instruction(opcode):
    ins_arithmetic_logic         = False
    ins_memory                   = False
    ins_stack                    = False
    ins_control_flow             = is_control_flow(opcode)
    ins_control_flow_conditional = False
    ins_system_io                = False
    ins_nop                      = False

    if is_arithmetic_logic(opcode):
        ins_arithmetic_logic = True
    elif is_memory(opcode):
        ins_memory = True
    elif is_stack(opcode):
        ins_stack = True
    elif ins_control_flow:
        ins_control_flow = True
        ins_control_flow_conditional = True
    elif is_control_flow_conditional(opcode):
        ins_control_flow_conditional = True
    elif is_system_io(opcode):
        ins_system_io = True
    elif is_nop(opcode):
        ins_nop = True

    return (ins_arithmetic_logic, ins_memory, ins_stack,    \
            ins_control_flow, ins_control_flow_conditional, \
            ins_system_io, ins_nop)


def modify_opcode_for_pass(d_opcode, mod_len, which_pass):
    if mod_len == 1:
        if which_pass > 0:
            return d_opcode
        else:
            # Replace byte with 0xc3
            return d_opcode[0:-2] + "c3"
    else:
        left  = -(mod_len*2) + (which_pass*2)
        right = -((mod_len-1)*2) + (which_pass*2)
        # Replace nth byte in word with 0xc3 (depending on pass)
        opc = d_opcode[0:left] + "c3"
        if right < 0:
            opc = opc + d_opcode[right:]
        return opc


def try_protect_immediate(opc, which_pass):
    (d_addr, d_opcode, d_mnemonic) = opc

    (opcode, operands) = split_opcode_from_operands(d_mnemonic)

    (ins_arithmetic_logic, ins_memory, ins_stack,    \
     ins_control_flow, ins_control_flow_conditional, \
     ins_system_io, ins_nop) = classify_instruction(opcode)
    if not ins_arithmetic_logic and not ins_memory and not ins_stack \
       and not ins_control_flow and not ins_control_flow_conditional \
       and not ins_system_io and not ins_nop:
       # Cannot classify this instruction, skip it
       return (d_opcode, 0)

    imm_ops = []
    if ins_control_flow:
        return (d_opcode, 0)
    else:
        for op in operands:    
            if "$" in op and not "(" in op:
                # Immediate operand, add to list and strip of the "$0x" prefix
                imm_ops.append(op[3:])
            elif "%" in op and not "(" in op:
                # Register direct operand
                pass
            else:
                # Memory or offset operand (includes things like es:(%edi))
                pass

    if ins_arithmetic_logic and len(imm_ops) > 0:
        if "add" in opcode or "adc" in opcode or "sub" in opcode or "sbb" in opcode:
            if len(imm_ops[0]) <= 2:
                return (modify_opcode_for_pass(d_opcode, 1, which_pass), 1)
            else:
                return (modify_opcode_for_pass(d_opcode, IMMEDIATE_LEN, which_pass), IMMEDIATE_LEN)
    elif ins_memory and len(imm_ops) > 0:
        if "mov" in opcode:
            if d_opcode[0:2] in [ "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", "c6" ]:
                return (modify_opcode_for_pass(d_opcode, 1, which_pass), 1)
            elif d_opcode[0:2] in ["b8", "b9", "ba", "bb", "bc", "bd", "be", "bf", "c7" ]:
                return (modify_opcode_for_pass(d_opcode, IMMEDIATE_LEN, which_pass), IMMEDIATE_LEN)

    return (d_opcode, 0)


def try_protect_offset(opc, which_pass):
    (d_addr, d_opcode, d_mnemonic) = opc

    (opcode, operands) = split_opcode_from_operands(d_mnemonic)

    (ins_arithmetic_logic, ins_memory, ins_stack,    \
     ins_control_flow, ins_control_flow_conditional, \
     ins_system_io, ins_nop) = classify_instruction(opcode)
    if not ins_arithmetic_logic and not ins_memory and not ins_stack \
       and not ins_control_flow and not ins_control_flow_conditional \
       and not ins_system_io and not ins_nop:
       # Cannot classify this instruction, skip it
       return (d_opcode, 0)

    offsets = []
    if not ins_control_flow:
        return (d_opcode, 0)

    # Call, long jump, absolute call/jmp, and jumps with two-byte opcodes have 
    # word offsets, all the others have byte offsets
    if d_opcode[0:2] in [ "e8", "e9", "ff", "0f" ]:
        return (modify_opcode_for_pass(d_opcode, OFFSET_LEN, which_pass), OFFSET_LEN)
    else:
        return (modify_opcode_for_pass(d_opcode, 1, which_pass), 1)

    return (d_opcode, 0)


def first_differing_index(str1, str2):
    i = 0
    while i < len(str1) and i < len(str2):
        if str1[i] != str2[i]:
            return i
        i = i + 1
    if len(str1) != len(str2):
        return i
    return -1


def gen_protected_immediates(opcodes_by_addr, which_pass):
    modified_immediates = []
    for i in range(0, len(opcodes_by_addr)):
        opc = opcodes_by_addr[i]
        (d_addr, d_opcode, d_mnemonic) = opc
        (d_opcode_new, imm_len) = try_protect_immediate(opc, which_pass)
        if d_opcode_new != d_opcode:
            # An immediate was modified, store the modified opcode bytes
            # and add the address of the first modified byte to the protected_addrs list
            opcodes_by_addr[i] = (d_addr, d_opcode_new, d_mnemonic)
            offset = first_differing_index(d_opcode, d_opcode_new)/2
            modified_immediates.append((d_addr + offset, imm_len))
            if debug:
                print "%s => %s (offset %d, imm_len %d)" % (d_opcode, d_opcode_new, offset, imm_len)
    if debug:
        print "Modified %d immediates" % (len(modified_immediates),)
    return modified_immediates


def gen_protected_offsets(opcodes_by_addr, which_pass):
    modified_offsets = []
    for i in range(0, len(opcodes_by_addr)):
        opc = opcodes_by_addr[i]
        (d_addr, d_opcode, d_mnemonic) = opc
        (d_opcode_new, off_len) = try_protect_offset(opc, which_pass)
        if d_opcode_new != d_opcode:
            # An offset was modified, store the modified opcode bytes
            # and add the address of the first modified byte to the protected_addrs list
            opcodes_by_addr[i] = (d_addr, d_opcode_new, d_mnemonic)
            offset = first_differing_index(d_opcode, d_opcode_new)/2
            modified_offsets.append((d_addr + offset, off_len))
            if debug:
                print "%s => %s (offset %d, off_len %d)" % (d_opcode, d_opcode_new, offset, off_len)
    if debug:
        print "Modified %d offsets" % (len(modified_offsets),)
    return modified_offsets


def count_code_bytes(opcodes_by_addr):
    count = 0
    for (d_addr, d_opcode, d_mnemonic) in opcodes_by_addr:
        count += len(d_opcode)/2
    return count


def get_opcodes_by_addr(binfile):
    # Disassemble binary file.
    try:
        disasm = subprocess.check_output(["objdump", "--wide", "-d", binfile])
    except OSError:
        raise Exception("cannot execute objdump")
    except subprocess.CalledProcessError:
        raise Exception("disassembly failed")

    # Parse disassembly into (address, opcode) tuples.
    opcodes_by_addr = []
    for line in iter(disasm.splitlines()):
        line = line.strip()
        try:
            (addr, opcode, mnemonic) = line.split("\t", 2)
            # Get the address in hex without trailing characters
            addr = addr.split(":", 1)[0].strip()
            # Convert the address to an integer
            addr = int(addr, base=16)
            # Get the opcode as a hex string
            opcode = "".join(opcode.split()).strip().lower()
            mnemonic = mnemonic.strip().lower()

            # Strip objdump comments from mnemonic
            if "<" in mnemonic:
                mnemonic = mnemonic.split("<", 1)[0].strip()

            # Ignore empty or commented mnemonics
            if not mnemonic or mnemonic[0] == "#":
                continue

            # Instruction names must start with a letter
            if not mnemonic[0].isalpha():
                continue

            opcodes_by_addr.append((addr, opcode, mnemonic))
        except:
            # Ignore bad lines.
            pass

    return opcodes_by_addr


def pct(x, y):
    if x == 0 or y == 0:
        return 0.0
    return float(x) / float(y) * 100.0


def main():
    if len(sys.argv) < 2:
        print >> sys.stderr, "Usage: %s <binary>" % (sys.argv[0])
        return 1

    binfile = sys.argv[1]

    try:
        opcodes_by_addr = get_opcodes_by_addr(binfile)
    except Exception as e:
        print >> sys.stderr, e
        return 1

    # For each heuristic, we maintain a list of the /unique/ (non-duplicate)
    # byte addresses that can be protected using that heuristic.
    protectable = {
        "existing"  : [], # gadgets which already existed in the binary
        "far-ret"   : [], # existing gadgets with far returns
        "immediate" : [], # gadgets created by modifying immediates
        "offset"    : [], # gadgets created by modifying jump and call offsets
        "all"       : []  # unique locations which can be protected by at least one of the heuristics
    }

    if debug:
        print "******* Existing gadgets *******"
    gadgets = scan_gadgets(opcodes_by_addr)
    for g in gadgets:
        if debug:
            print "0x%016x (%-2d): %s (%s)" % (g[0], g[1], "; ".join(g[3].split("\n")), g[2])
        for addr in range(g[0], g[0] + g[1]):
            if addr not in protectable["existing"]:
                protectable["existing"].append(addr)
    existing_gadgets = list(gadgets)

    if debug:
        print "******* Far return gadgets *******"
    gadgets = scan_gadgets(opcodes_by_addr, True)
    for g in gadgets:
        if debug:
            print "0x%016x (%-2d): %s (%s)" % (g[0], g[1], "; ".join(g[3].split("\n")), g[2])
        for addr in range(g[0], g[0] + g[1]):
            if addr not in protectable["far-ret"]:
                protectable["far-ret"].append(addr)

    if debug:
        print "******* Modified immediates *******"
    for i in range(0, IMMEDIATE_LEN):
        if debug:
            print "    *** Pass %d ***" % (i,)
        n = len(protectable["immediate"])
        opcodes_by_addr_tmp = list(opcodes_by_addr)
        modified_immediates = gen_protected_immediates(opcodes_by_addr_tmp, i)
        gadgets = scan_gadgets(opcodes_by_addr_tmp)
        for g in gadgets:
            if g in existing_gadgets:
                # This is not a newly created gadget, skip it
                continue
            if debug:
                print "0x%016x (%-2d): %s (%s)" % (g[0], g[1], "; ".join(g[3].split("\n")), g[2])
            for addr in range(g[0], g[0] + g[1]):
                if addr not in protectable["immediate"]:
                    protectable["immediate"].append(addr)
        if debug:
            print "Protected %d new locations in pass %d" % (len(protectable["immediate"]) - n, i)

    if debug:
        print "******* Modified jump/call offsets *******"
    for i in range(0, OFFSET_LEN):
        if debug:
            print "    *** Pass %d ***" % (i,)
        n = len(protectable["offset"])
        opcodes_by_addr_tmp = list(opcodes_by_addr)
        modified_offsets = gen_protected_offsets(opcodes_by_addr_tmp, i)
        gadgets = scan_gadgets(opcodes_by_addr_tmp)
        for g in gadgets:
            if g in existing_gadgets:
                # This is not a newly created gadget, skip it
                continue
            if debug:
                print "0x%016x (%-2d): %s (%s)" % (g[0], g[1], "; ".join(g[3].split("\n")), g[2])
            for addr in range(g[0], g[0] + g[1]):
                if addr not in protectable["offset"]:
                    protectable["offset"].append(addr)
        if debug:
            print "Protected %d new locations in pass %d" % (len(protectable["offset"]) - n, i)

    protectable["all"] = list(set(protectable["existing"]) | set(protectable["far-ret"]) | set(protectable["immediate"]) | set(protectable["offset"]))
    nr_code_bytes = count_code_bytes(opcodes_by_addr)

    if debug:
        print "******* Report *******"
        print

    g_bytes_existing  = len(protectable["existing"])
    g_bytes_far_ret   = len(protectable["far-ret"])
    g_bytes_immediate = len(protectable["immediate"])
    g_bytes_offset    = len(protectable["offset"])
    g_bytes_all       = len(protectable["all"])

    if brief:
        print "%d;%d,%d,%d,%d,%d;%f,%f,%f,%f,%f" % (
              nr_code_bytes, 
              g_bytes_existing, g_bytes_far_ret, g_bytes_immediate, g_bytes_offset, g_bytes_all,
              pct(g_bytes_existing, nr_code_bytes), pct(g_bytes_far_ret, nr_code_bytes),
              pct(g_bytes_immediate, nr_code_bytes), pct(g_bytes_offset, nr_code_bytes),
              pct(g_bytes_all, nr_code_bytes))
    else:
        print "+--------------------------------------------------------------------+"
        print "|            |         bytes protectable by gadget type              |"
        print "| code bytes | existing | far return | immediate |  offset |     any |"
        print "+--------------------------------------------------------------------+"
        print "| %10d | %8d | %10d | %9d | %7d | %7d |" % (
              nr_code_bytes, g_bytes_existing, g_bytes_far_ret, g_bytes_immediate, g_bytes_offset, g_bytes_all)
        print "|            | %8.2f | %10.2f | %9.2f | %7.2f | %7.2f |" % (
              pct(g_bytes_existing, nr_code_bytes), pct(g_bytes_far_ret, nr_code_bytes),
              pct(g_bytes_immediate, nr_code_bytes), pct(g_bytes_offset, nr_code_bytes),
              pct(g_bytes_all, nr_code_bytes))
        print "+--------------------------------------------------------------------+"

    return 0

if __name__ == "__main__":
    sys.exit(main())


