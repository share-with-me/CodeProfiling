/*
 * Copyright (c) 1999, 2001 Hewlett-Packard Co
 *	David Mosberger-Tang <davidm@hpl.hp.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * IA-32 syscalls that have pointer arguments which are incompatible
 * with 64-bit layout get redirected to printargs.
 */
#undef SYS_FUNC_NAME
#define SYS_FUNC_NAME(syscall_name) printargs
#include "../i386/syscallent.h"
#undef SYS_FUNC_NAME
#define SYS_FUNC_NAME(syscall_name) MPERS_FUNC_NAME(syscall_name)

/* You must be careful to check ../i386/syscallent.h so that this table
   starts where that one leaves off.
*/
[(SYS_ipc_subcall + SYS_ipc_nsubcalls) ... 1023] = { },
[1024] = { 0,	0,		SEN(printargs),			"ni_syscall"		},
[1025] = { 1,	TP|SE,		SEN(exit),			"exit"			},
[1026] = { 3,	TD,		SEN(read),			"read"			},
[1027] = { 3,	TD,		SEN(write),			"write"			},
[1028] = { 3,	TD|TF,		SEN(open),			"open"			},
[1029] = { 1,	TD,		SEN(close),			"close"			},
[1030] = { 2,	TD|TF,		SEN(creat),			"creat"			},
[1031] = { 2,	TF,		SEN(link),			"link"			},
[1032] = { 1,	TF,		SEN(unlink),			"unlink"		},
[1033] = { 3,	TF|TP|SE|SI,	SEN(execve),			"execve"		},
[1034] = { 1,	TF,		SEN(chdir),			"chdir"			},
[1035] = { 1,	TD,		SEN(fchdir),			"fchdir"		},
[1036] = { 2,	TF,		SEN(utimes),			"utimes"		},
[1037] = { 3,	TF,		SEN(mknod),			"mknod"			},
[1038] = { 2,	TF,		SEN(chmod),			"chmod"			},
[1039] = { 3,	TF,		SEN(chown),			"chown"			},
[1040] = { 3,	TD,		SEN(lseek),			"lseek"			},
[1041] = { 0,	NF,		SEN(getpid),			"getpid"		},
[1042] = { 0,	NF,		SEN(getppid),			"getppid"		},
[1043] = { 5,	TF,		SEN(mount),			"mount"			},
[1044] = { 2,	TF,		SEN(umount2),			"umount"		},
[1045] = { 1,	0,		SEN(setuid),			"setuid"		},
[1046] = { 0,	NF,		SEN(getuid),			"getuid"		},
[1047] = { 0,	NF,		SEN(geteuid),			"geteuid"		},
[1048] = { 4,	0,		SEN(ptrace),			"ptrace"		},
[1049] = { 2,	TF,		SEN(access),			"access"		},
[1050] = { 0,	0,		SEN(sync),			"sync"			},
[1051] = { 1,	TD,		SEN(fsync),			"fsync"			},
[1052] = { 1,	TD,		SEN(fdatasync),			"fdatasync"		},
[1053] = { 2,	TS,		SEN(kill),			"kill"			},
[1054] = { 2,	TF,		SEN(rename),			"rename"		},
[1055] = { 2,	TF,		SEN(mkdir),			"mkdir"			},
[1056] = { 1,	TF,		SEN(rmdir),			"rmdir"			},
[1057] = { 1,	TD,		SEN(dup),			"dup"			},
[1058] = { 0,	TD,		SEN(pipe),			"pipe"			},
[1059] = { 1,	0,		SEN(times),			"times"			},
[1060] = { 1,	TM|SI,		SEN(brk),			"brk"			},
[1061] = { 1,	0,		SEN(setgid),			"setgid"		},
[1062] = { 0,	NF,		SEN(getgid),			"getgid"		},
[1063] = { 0,	NF,		SEN(getegid),			"getegid"		},
[1064] = { 1,	TF,		SEN(acct),			"acct"			},
[1065] = { 3,	TD,		SEN(ioctl),			"ioctl"			},
[1066] = { 3,	TD,		SEN(fcntl),			"fcntl"			},
[1067] = { 1,	NF,		SEN(umask),			"umask"			},
[1068] = { 1,	TF,		SEN(chroot),			"chroot"		},
[1069] = { 2,	0,		SEN(ustat),			"ustat"			},
[1070] = { 2,	TD,		SEN(dup2),			"dup2"			},
[1071] = { 2,	0,		SEN(setreuid),			"setreuid"		},
[1072] = { 2,	0,		SEN(setregid),			"setregid"		},
[1073] = { 3,	0,		SEN(getresuid),			"getresuid"		},
[1074] = { 3,	0,		SEN(setresuid),			"setresuid"		},
[1075] = { 3,	0,		SEN(getresgid),			"getresgid"		},
[1076] = { 3,	0,		SEN(setresgid),			"setresgid"		},
[1077] = { 2,	0,		SEN(getgroups),			"getgroups"		},
[1078] = { 2,	0,		SEN(setgroups),			"setgroups"		},
[1079] = { 1,	0,		SEN(getpgid),			"getpgid"		},
[1080] = { 2,	0,		SEN(setpgid),			"setpgid"		},
[1081] = { 0,	0,		SEN(setsid),			"setsid"		},
[1082] = { 1,	0,		SEN(getsid),			"getsid"		},
[1083] = { 2,	0,		SEN(sethostname),		"sethostname"		},
[1084] = { 2,	0,		SEN(setrlimit),			"setrlimit"		},
[1085] = { 2,	0,		SEN(getrlimit),			"getrlimit"		},
[1086] = { 2,	0,		SEN(getrusage),			"getrusage"		},
[1087] = { 2,	0,		SEN(gettimeofday),		"gettimeofday"		},
[1088] = { 2,	0,		SEN(settimeofday),		"settimeofday"		},
[1089] = { 5,	TD,		SEN(select),			"select"		},
[1090] = { 3,	TD,		SEN(poll),			"poll"			},
[1091] = { 2,	TF,		SEN(symlink),			"symlink"		},
[1092] = { 3,	TF,		SEN(readlink),			"readlink"		},
[1093] = { 1,	TF,		SEN(uselib),			"uselib"		},
[1094] = { 2,	TF,		SEN(swapon),			"swapon"		},
[1095] = { 1,	TF,		SEN(swapoff),			"swapoff"		},
[1096] = { 4,	0,		SEN(reboot),			"reboot"		},
[1097] = { 2,	TF,		SEN(truncate),			"truncate"		},
[1098] = { 2,	TD,		SEN(ftruncate),			"ftruncate"		},
[1099] = { 2,	TD,		SEN(fchmod),			"fchmod"		},
[1100] = { 3,	TD,		SEN(fchown),			"fchown"		},
[1101] = { 2,	0,		SEN(getpriority),		"getpriority"		},
[1102] = { 3,	0,		SEN(setpriority),		"setpriority"		},
[1103] = { 2,	TF,		SEN(statfs),			"statfs"		},
[1104] = { 2,	TD,		SEN(fstatfs),			"fstatfs"		},
[1105] = { 0,	NF,		SEN(gettid),			"gettid"		},
[1106] = { 3,	TI,		SEN(semget),			"semget"		},
[1107] = { 3,	TI,		SEN(semop),			"semop"			},
[1108] = { 4,	TI,		SEN(semctl),			"semctl"		},
[1109] = { 2,	TI,		SEN(msgget),			"msgget"		},
[1110] = { 4,	TI,		SEN(msgsnd),			"msgsnd"		},
[1111] = { 5,	TI,		SEN(msgrcv),			"msgrcv"		},
[1112] = { 3,	TI,		SEN(msgctl),			"msgctl"		},
[1113] = { 3,	TI,		SEN(shmget),			"shmget"		},
[1114] = { 3,	TI|TM|SI,	SEN(shmat),			"shmat"			},
[1115] = { 1,	TI|TM|SI,	SEN(shmdt),			"shmdt"			},
[1116] = { 3,	TI,		SEN(shmctl),			"shmctl"		},
[1117] = { 3,	0,		SEN(syslog),			"syslog"		},
[1118] = { 3,	0,		SEN(setitimer),			"setitimer"		},
[1119] = { 2,	0,		SEN(getitimer),			"getitimer"		},
[1120] = { 2,	TF,		SEN(stat),			"stat"			},
[1121] = { 2,	TF,		SEN(lstat),			"lstat"			},
[1122] = { 2,	TD,		SEN(fstat),			"fstat"			},
[1123] = { 0,	0,		SEN(vhangup),			"vhangup"		},
[1124] = { 3,	TF,		SEN(chown),			"lchown"		},
[1125] = { 5,	TM|SI,		SEN(remap_file_pages),		"remap_file_pages"	},
[1126] = { 4,	TP,		SEN(wait4),			"wait4"			},
[1127] = { 1,	0,		SEN(sysinfo),			"sysinfo"		},
[1128] = { 5,	TP,		SEN(clone),			"clone"			},
[1129] = { 2,	0,		SEN(setdomainname),		"setdomainname"		},
[1130] = { 1,	0,		SEN(uname),			"uname"			},
[1131] = { 1,	0,		SEN(adjtimex),			"adjtimex"		},
[1132] = { 2,	0,		SEN(create_module),		"create_module"		},
[1133] = { 3,	0,		SEN(init_module),		"init_module"		},
[1134] = { 2,	0,		SEN(delete_module),		"delete_module"		},
[1135] = { 1,	0,		SEN(get_kernel_syms),		"get_kernel_syms"	},
[1136] = { 5,	0,		SEN(query_module),		"query_module"		},
[1137] = { 4,	TF,		SEN(quotactl),			"quotactl"		},
[1138] = { 2,	0,		SEN(bdflush),			"bdflush"		},
[1139] = { 3,	0,		SEN(sysfs),			"sysfs"			},
[1140] = { 1,	NF,		SEN(personality),		"personality"		},
[1141] = { 5,	0,		SEN(afs_syscall),		"afs_syscall"		},
[1142] = { 1,	NF,		SEN(setfsuid),			"setfsuid"		},
[1143] = { 1,	NF,		SEN(setfsgid),			"setfsgid"		},
[1144] = { 3,	TD,		SEN(getdents),			"getdents"		},
[1145] = { 2,	TD,		SEN(flock),			"flock"			},
[1146] = { 3,	TD,		SEN(readv),			"readv"			},
[1147] = { 3,	TD,		SEN(writev),			"writev"		},
[1148] = { 4,	TD,		SEN(pread),			"pread64"		},
[1149] = { 4,	TD,		SEN(pwrite),			"pwrite64"		},
[1150] = { 1,	0,		SEN(printargs),			"_sysctl"		},
[1151] = { 6,	TD|TM|SI,	SEN(mmap),			"mmap"			},
[1152] = { 2,	TM|SI,		SEN(munmap),			"munmap"		},
[1153] = { 2,	TM,		SEN(mlock),			"mlock"			},
[1154] = { 1,	TM,		SEN(mlockall),			"mlockall"		},
[1155] = { 3,	TM|SI,		SEN(mprotect),			"mprotect"		},
[1156] = { 5,	TM|SI,		SEN(mremap),			"mremap"		},
[1157] = { 3,	TM,		SEN(msync),			"msync"			},
[1158] = { 2,	TM,		SEN(munlock),			"munlock"		},
[1159] = { 0,	TM,		SEN(munlockall),		"munlockall"		},
[1160] = { 2,	0,		SEN(sched_getparam),		"sched_getparam"	},
[1161] = { 2,	0,		SEN(sched_setparam),		"sched_setparam"	},
[1162] = { 1,	0,		SEN(sched_getscheduler),	"sched_getscheduler"	},
[1163] = { 3,	0,		SEN(sched_setscheduler),	"sched_setscheduler"	},
[1164] = { 0,	0,		SEN(sched_yield),		"sched_yield"		},
[1165] = { 1,	0,		SEN(sched_get_priority_max),	"sched_get_priority_max"},
[1166] = { 1,	0,		SEN(sched_get_priority_min),	"sched_get_priority_min"},
[1167] = { 2,	0,		SEN(sched_rr_get_interval),	"sched_rr_get_interval"	},
[1168] = { 2,	0,		SEN(nanosleep),			"nanosleep"		},
[1169] = { 3,	0,		SEN(nfsservctl),		"nfsservctl"		},
[1170] = { 5,	0,		SEN(prctl),			"prctl"			},
[1171] = { 0,	0,		SEN(getpagesize),		"getpagesize"		},
[1172] = { 6,	TD|TM|SI,	SEN(mmap_pgoff),		"mmap2"			},
[1173] = { 5,	0,		SEN(printargs),			"pciconfig_read"	},
[1174] = { 5,	0,		SEN(printargs),			"pciconfig_write"	},
[1175] = { MA,	0,		SEN(printargs),			"perfmonctl"		},
[1176] = { 2,	TS,		SEN(sigaltstack),		"sigaltstack"		},
[1177] = { 4,	TS,		SEN(rt_sigaction),		"rt_sigaction"		},
[1178] = { 2,	TS,		SEN(rt_sigpending),		"rt_sigpending"		},
[1179] = { 4,	TS,		SEN(rt_sigprocmask),		"rt_sigprocmask"	},
[1180] = { 3,	TS,		SEN(rt_sigqueueinfo),		"rt_sigqueueinfo"	},
[1181] = { 0,	TS,		SEN(sigreturn),			"rt_sigreturn"		},
[1182] = { 2,	TS,		SEN(rt_sigsuspend),		"rt_sigsuspend"		},
[1183] = { 4,	TS,		SEN(rt_sigtimedwait),		"rt_sigtimedwait"	},
[1184] = { 2,	TF,		SEN(getcwd),			"getcwd"		},
[1185] = { 2,	0,		SEN(capget),			"capget"		},
[1186] = { 2,	0,		SEN(capset),			"capset"		},
[1187] = { 4,	TD|TN,		SEN(sendfile),			"sendfile"		},
[1188] = { 5,	TN,		SEN(getpmsg),			"getpmsg"		},
[1189] = { 5,	TN,		SEN(putpmsg),			"putpmsg"		},
[1190] = { 3,	TN,		SEN(socket),			"socket"		},
[1191] = { 3,	TN,		SEN(bind),			"bind"			},
[1192] = { 3,	TN,		SEN(connect),			"connect"		},
[1193] = { 2,	TN,		SEN(listen),			"listen"		},
[1194] = { 3,	TN,		SEN(accept),			"accept"		},
[1195] = { 3,	TN,		SEN(getsockname),		"getsockname"		},
[1196] = { 3,	TN,		SEN(getpeername),		"getpeername"		},
[1197] = { 4,	TN,		SEN(socketpair),		"socketpair"		},
[1198] = { 4,	TN,		SEN(send),			"send"			},
[1199] = { 6,	TN,		SEN(sendto),			"sendto"		},
[1200] = { 4,	TN,		SEN(recv),			"recv"			},
[1201] = { 6,	TN,		SEN(recvfrom),			"recvfrom"		},
[1202] = { 2,	TN,		SEN(shutdown),			"shutdown"		},
[1203] = { 5,	TN,		SEN(setsockopt),		"setsockopt"		},
[1204] = { 5,	TN,		SEN(getsockopt),		"getsockopt"		},
[1205] = { 3,	TN,		SEN(sendmsg),			"sendmsg"		},
[1206] = { 3,	TN,		SEN(recvmsg),			"recvmsg"		},
[1207] = { 2,	TF,		SEN(pivotroot),			"pivot_root"		},
[1208] = { 3,	TM,		SEN(mincore),			"mincore"		},
[1209] = { 3,	TM,		SEN(madvise),			"madvise"		},
[1210] = { 2,	TF,		SEN(stat),			"stat"			},
[1211] = { 2,	TF,		SEN(lstat),			"lstat"			},
[1212] = { 2,	TD,		SEN(fstat),			"fstat"			},
[1213] = { 6,	TP,		SEN(clone),			"clone2"		},
[1214] = { 3,	TD,		SEN(getdents64),		"getdents64"		},
[1215] = { 2,	0,		SEN(printargs),			"getunwind"		},
[1216] = { 3,	TD,		SEN(readahead),			"readahead"		},
[1217] = { 5,	TF,		SEN(setxattr),			"setxattr"		},
[1218] = { 5,	TF,		SEN(setxattr),			"lsetxattr"		},
[1219] = { 5,	TD,		SEN(fsetxattr),			"fsetxattr"		},
[1220] = { 4,	TF,		SEN(getxattr),			"getxattr"		},
[1221] = { 4,	TF,		SEN(getxattr),			"lgetxattr"		},
[1222] = { 4,	TD,		SEN(fgetxattr),			"fgetxattr"		},
[1223] = { 3,	TF,		SEN(listxattr),			"listxattr"		},
[1224] = { 3,	TF,		SEN(listxattr),			"llistxattr"		},
[1225] = { 3,	TD,		SEN(flistxattr),		"flistxattr"		},
[1226] = { 2,	TF,		SEN(removexattr),		"removexattr"		},
[1227] = { 2,	TF,		SEN(removexattr),		"lremovexattr"		},
[1228] = { 2,	TD,		SEN(fremovexattr),		"fremovexattr"		},
[1229] = { 2,	TS,		SEN(kill),			"tkill"			},
[1230] = { 6,	0,		SEN(futex),			"futex"			},
[1231] = { 3,	0,		SEN(sched_setaffinity),		"sched_setaffinity"	},
[1232] = { 3,	0,		SEN(sched_getaffinity),		"sched_getaffinity"	},
[1233] = { 1,	0,		SEN(set_tid_address),		"set_tid_address"	},
[1234] = { 4,	TD,		SEN(fadvise64),			"fadvise64"		},
[1235] = { 3,	TS,		SEN(tgkill),			"tgkill"		},
[1236] = { 1,	TP|SE,		SEN(exit),			"exit_group"		},
[1237] = { 3,	0,		SEN(lookup_dcookie),		"lookup_dcookie"	},
[1238] = { 2,	TM,		SEN(io_setup),			"io_setup"		},
[1239] = { 1,	TM,		SEN(io_destroy),		"io_destroy"		},
[1240] = { 5,	0,		SEN(io_getevents),		"io_getevents"		},
[1241] = { 3,	0,		SEN(io_submit),			"io_submit"		},
[1242] = { 3,	0,		SEN(io_cancel),			"io_cancel"		},
[1243] = { 1,	TD,		SEN(epoll_create),		"epoll_create"		},
[1244] = { 4,	TD,		SEN(epoll_ctl),			"epoll_ctl"		},
[1245] = { 4,	TD,		SEN(epoll_wait),		"epoll_wait"		},
[1246] = { 0,	0,		SEN(restart_syscall),		"restart_syscall"	},
[1247] = { 4,	TI,		SEN(semtimedop),		"semtimedop"		},
[1248] = { 3,	0,		SEN(timer_create),		"timer_create"		},
[1249] = { 4,	0,		SEN(timer_settime),		"timer_settime"		},
[1250] = { 2,	0,		SEN(timer_gettime),		"timer_gettime"		},
[1251] = { 1,	0,		SEN(timer_getoverrun),		"timer_getoverrun"	},
[1252] = { 1,	0,		SEN(timer_delete),		"timer_delete"		},
[1253] = { 2,	0,		SEN(clock_settime),		"clock_settime"		},
[1254] = { 2,	0,		SEN(clock_gettime),		"clock_gettime"		},
[1255] = { 2,	0,		SEN(clock_getres),		"clock_getres"		},
[1256] = { 4,	0,		SEN(clock_nanosleep),		"clock_nanosleep"	},
[1257] = { 3,	TD,		SEN(fstatfs64),			"fstatfs64"		},
[1258] = { 3,	TF,		SEN(statfs64),			"statfs64"		},
[1259] = { 6,	TM,		SEN(mbind),			"mbind"			},
[1260] = { 5,	TM,		SEN(get_mempolicy),		"get_mempolicy"		},
[1261] = { 3,	TM,		SEN(set_mempolicy),		"set_mempolicy"		},
[1262] = { 4,	0,		SEN(mq_open),			"mq_open"		},
[1263] = { 1,	0,		SEN(mq_unlink),			"mq_unlink"		},
[1264] = { 5,	0,		SEN(mq_timedsend),		"mq_timedsend"		},
[1265] = { 5,	0,		SEN(mq_timedreceive),		"mq_timedreceive"	},
[1266] = { 2,	0,		SEN(mq_notify),			"mq_notify"		},
[1267] = { 3,	0,		SEN(mq_getsetattr),		"mq_getsetattr"		},
[1268] = { 4,	0,		SEN(kexec_load),		"kexec_load"		},
[1269] = { 5,	0,		SEN(vserver),			"vserver"		},
[1270] = { 5,	TP,		SEN(waitid),			"waitid"		},
[1271] = { 5,	0,		SEN(add_key),			"add_key"		},
[1272] = { 4,	0,		SEN(request_key),		"request_key"		},
[1273] = { 5,	0,		SEN(keyctl),			"keyctl"		},
[1274] = { 3,	0,		SEN(ioprio_set),		"ioprio_set"		},
[1275] = { 2,	0,		SEN(ioprio_get),		"ioprio_get"		},
[1276] = { 6,	TM,		SEN(move_pages),		"move_pages"		},
[1277] = { 0,	TD,		SEN(inotify_init),		"inotify_init"		},
[1278] = { 3,	TD,		SEN(inotify_add_watch),		"inotify_add_watch"	},
[1279] = { 2,	TD,		SEN(inotify_rm_watch),		"inotify_rm_watch"	},
[1280] = { 4,	TM,		SEN(migrate_pages),		"migrate_pages"		},
[1281] = { 4,	TD|TF,		SEN(openat),			"openat"		},
[1282] = { 3,	TD|TF,		SEN(mkdirat),			"mkdirat"		},
[1283] = { 4,	TD|TF,		SEN(mknodat),			"mknodat"		},
[1284] = { 5,	TD|TF,		SEN(fchownat),			"fchownat"		},
[1285] = { 3,	TD|TF,		SEN(futimesat),			"futimesat"		},
[1286] = { 4,	TD|TF,		SEN(newfstatat),		"newfstatat"		},
[1287] = { 3,	TD|TF,		SEN(unlinkat),			"unlinkat"		},
[1288] = { 4,	TD|TF,		SEN(renameat),			"renameat"		},
[1289] = { 5,	TD|TF,		SEN(linkat),			"linkat"		},
[1290] = { 3,	TD|TF,		SEN(symlinkat),			"symlinkat"		},
[1291] = { 4,	TD|TF,		SEN(readlinkat),		"readlinkat"		},
[1292] = { 3,	TD|TF,		SEN(fchmodat),			"fchmodat"		},
[1293] = { 3,	TD|TF,		SEN(faccessat),			"faccessat"		},
[1294] = { 6,	TD,		SEN(pselect6),			"pselect6"		},
[1295] = { 5,	TD,		SEN(ppoll),			"ppoll"			},
[1296] = { 1,	TP,		SEN(unshare),			"unshare"		},
[1297] = { 6,	TD,		SEN(splice),			"splice"		},
[1298] = { 2,	0,		SEN(set_robust_list),		"set_robust_list"	},
[1299] = { 3,	0,		SEN(get_robust_list),		"get_robust_list"	},
[1300] = { 4,	TD,		SEN(sync_file_range),		"sync_file_range"	},
[1301] = { 4,	TD,		SEN(tee),			"tee"			},
[1302] = { 4,	TD,		SEN(vmsplice),			"vmsplice"		},
[1303] = { 4,	TD,		SEN(fallocate),			"fallocate"		},
[1304] = { 3,	0,		SEN(getcpu),			"getcpu"		},
[1305] = { 6,	TD,		SEN(epoll_pwait),		"epoll_pwait"		},
[1306] = { 4,	TD|TF,		SEN(utimensat),			"utimensat"		},
[1307] = { 3,	TD|TS,		SEN(signalfd),			"signalfd"		},
[1308] = { 4,	TD,		SEN(timerfd),			"timerfd"		},
[1309] = { 1,	TD,		SEN(eventfd),			"eventfd"		},
[1310] = { 2,	TD,		SEN(timerfd_create),		"timerfd_create"	},
[1311] = { 4,	TD,		SEN(timerfd_settime),		"timerfd_settime"	},
[1312] = { 2,	TD,		SEN(timerfd_gettime),		"timerfd_gettime"	},
[1313] = { 4,	TD|TS,		SEN(signalfd4),			"signalfd4"		},
[1314] = { 2,	TD,		SEN(eventfd2),			"eventfd2"		},
[1315] = { 1,	TD,		SEN(epoll_create1),		"epoll_create1"		},
[1316] = { 3,	TD,		SEN(dup3),			"dup3"			},
[1317] = { 2,	TD,		SEN(pipe2),			"pipe2"			},
[1318] = { 1,	TD,		SEN(inotify_init1),		"inotify_init1"		},
[1319] = { 4,	TD,		SEN(preadv),			"preadv"		},
[1320] = { 4,	TD,		SEN(pwritev),			"pwritev"		},
[1321] = { 4,	TP|TS,		SEN(rt_tgsigqueueinfo),		"rt_tgsigqueueinfo"	},
[1322] = { 5,	TN,		SEN(recvmmsg),			"recvmmsg"		},
[1323] = { 2,	TD,		SEN(fanotify_init),		"fanotify_init"		},
[1324] = { 5,	TD|TF,		SEN(fanotify_mark),		"fanotify_mark"		},
[1325] = { 4,	0,		SEN(prlimit64),			"prlimit64"		},
[1326] = { 5,	TD|TF,		SEN(name_to_handle_at),		"name_to_handle_at"	},
[1327] = { 3,	TD,		SEN(open_by_handle_at),		"open_by_handle_at"	},
[1328] = { 2,	0,		SEN(clock_adjtime),		"clock_adjtime"		},
[1329] = { 1,	TD,		SEN(syncfs),			"syncfs"		},
[1330] = { 2,	TD,		SEN(setns),			"setns"			},
[1331] = { 4,	TN,		SEN(sendmmsg),			"sendmmsg"		},
[1332] = { 6,	0,		SEN(process_vm_readv),		"process_vm_readv"	},
[1333] = { 6,	0,		SEN(process_vm_writev),		"process_vm_writev"	},
[1334] = { 4,	TN,		SEN(accept4),			"accept4"		},
[1335] = { 3,	TD,		SEN(finit_module),		"finit_module"		},
[1336] = { 3,	0,		SEN(sched_setattr),		"sched_setattr"		},
[1337] = { 4,	0,		SEN(sched_getattr),		"sched_getattr"		},
[1338] = { 5,	TD|TF,		SEN(renameat2),			"renameat2"		},
[1339] = { 3,	0,		SEN(getrandom),			"getrandom",		},
[1340] = { 2,	TD,		SEN(memfd_create),		"memfd_create",		},
[1341] = { 3,	TD,		SEN(bpf),			"bpf",			},
[1342] = { 5,	TD|TF|TP|SE|SI,	SEN(execveat),			"execveat",		},
[1343] = { 1,	TD,		SEN(userfaultfd),		"userfaultfd",		},
[1344] = { 2,	0,		SEN(membarrier),		"membarrier",		},
[1345] = { 5,	0,		SEN(kcmp),			"kcmp"			},
[1346] = { 3,	TM,		SEN(mlock2),			"mlock2"		},
[1347] = { 6,	TD,		SEN(copy_file_range),		"copy_file_range"	},
[1348] = { 6,	TD,		SEN(preadv2),			"preadv2"		},
[1349] = { 6,	TD,		SEN(pwritev2),			"pwritev2"		},
