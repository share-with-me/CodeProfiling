#if defined LINUX_MIPSN32
/* For an N32 strace decode the N32 64-bit syscalls. */
[6000] = { 3,	TD,		SEN(read),			"read"			}, /* start of Linux N32 */
[6001] = { 3,	TD,		SEN(write),			"write"			},
[6002] = { 3,	TD|TF,		SEN(open),			"open"			},
[6003] = { 1,	TD,		SEN(close),			"close"			},
[6004] = { 2,	TF,		SEN(stat64),			"stat"			},
[6005] = { 2,	TD,		SEN(fstat64),			"fstat"			},
[6006] = { 2,	TF,		SEN(lstat64),			"lstat"			},
[6007] = { 3,	TD,		SEN(poll),			"poll"			},
[6008] = { 3,	TD,		SEN(lseek),			"lseek"			},
[6009] = { 6,	TD|TM|SI,	SEN(mmap),			"mmap"			},
[6010] = { 3,	TM|SI,		SEN(mprotect),			"mprotect"		},
[6011] = { 2,	TM|SI,		SEN(munmap),			"munmap"		},
[6012] = { 1,	TM|SI,		SEN(brk),			"brk"			},
[6013] = { 4,	TS,		SEN(rt_sigaction),		"rt_sigaction"		},
[6014] = { 4,	TS,		SEN(rt_sigprocmask),		"rt_sigprocmask"	},
[6015] = { 3,	TD,		SEN(ioctl),			"ioctl"			},
[6016] = { 4,	TD,		SEN(pread),			"pread64"		},
[6017] = { 4,	TD,		SEN(pwrite),			"pwrite64"		},
[6018] = { 3,	TD,		SEN(readv),			"readv"			},
[6019] = { 3,	TD,		SEN(writev),			"writev"		},
[6020] = { 2,	TF,		SEN(access),			"access"		},
[6021] = { 0,	TD,		SEN(pipe),			"pipe"			},
[6022] = { 5,	TD,		SEN(select),			"_newselect"		},
[6023] = { 0,	0,		SEN(sched_yield),		"sched_yield"		},
[6024] = { 5,	TM|SI,		SEN(mremap),			"mremap"		},
[6025] = { 3,	TM,		SEN(msync),			"msync"			},
[6026] = { 3,	TM,		SEN(mincore),			"mincore"		},
[6027] = { 3,	TM,		SEN(madvise),			"madvise"		},
[6028] = { 3,	TI,		SEN(shmget),			"shmget"		},
[6029] = { 3,	TI|TM|SI,	SEN(shmat),			"shmat"			},
[6030] = { 3,	TI,		SEN(shmctl),			"shmctl"		},
[6031] = { 1,	TD,		SEN(dup),			"dup"			},
[6032] = { 2,	TD,		SEN(dup2),			"dup2"			},
[6033] = { 0,	TS,		SEN(pause),			"pause"			},
[6034] = { 2,	0,		SEN(nanosleep),			"nanosleep"		},
[6035] = { 2,	0,		SEN(getitimer),			"getitimer"		},
[6036] = { 3,	0,		SEN(setitimer),			"setitimer"		},
[6037] = { 1,	0,		SEN(alarm),			"alarm"			},
[6038] = { 0,	NF,		SEN(getpid),			"getpid"		},
[6039] = { 4,	TD|TN,		SEN(sendfile),			"sendfile"		},
[6040] = { 3,	TN,		SEN(socket),			"socket"		},
[6041] = { 3,	TN,		SEN(connect),			"connect"		},
[6042] = { 3,	TN,		SEN(accept),			"accept"		},
[6043] = { 6,	TN,		SEN(sendto),			"sendto"		},
[6044] = { 6,	TN,		SEN(recvfrom),			"recvfrom"		},
[6045] = { 3,	TN,		SEN(sendmsg),			"sendmsg"		},
[6046] = { 3,	TN,		SEN(recvmsg),			"recvmsg"		},
[6047] = { 2,	TN,		SEN(shutdown),			"shutdown"		},
[6048] = { 3,	TN,		SEN(bind),			"bind"			},
[6049] = { 2,	TN,		SEN(listen),			"listen"		},
[6050] = { 3,	TN,		SEN(getsockname),		"getsockname"		},
[6051] = { 3,	TN,		SEN(getpeername),		"getpeername"		},
[6052] = { 4,	TN,		SEN(socketpair),		"socketpair"		},
[6053] = { 5,	TN,		SEN(setsockopt),		"setsockopt"		},
[6054] = { 5,	TN,		SEN(getsockopt),		"getsockopt"		},
[6055] = { 5,	TP,		SEN(clone),			"clone"			},
[6056] = { 0,	TP,		SEN(fork),			"fork"			},
[6057] = { 3,	TF|TP|SE|SI,	SEN(execve),			"execve"		},
[6058] = { 1,	TP|SE,		SEN(exit),			"exit"			},
[6059] = { 4,	TP,		SEN(wait4),			"wait4"			},
[6060] = { 2,	TS,		SEN(kill),			"kill"			},
[6061] = { 1,	0,		SEN(uname),			"uname"			},
[6062] = { 3,	TI,		SEN(semget),			"semget"		},
[6063] = { 3,	TI,		SEN(semop),			"semop"			},
[6064] = { 4,	TI,		SEN(semctl),			"semctl"		},
[6065] = { 1,	TI|TM|SI,	SEN(shmdt),			"shmdt"			},
[6066] = { 2,	TI,		SEN(msgget),			"msgget"		},
[6067] = { 4,	TI,		SEN(msgsnd),			"msgsnd"		},
[6068] = { 5,	TI,		SEN(msgrcv),			"msgrcv"		},
[6069] = { 3,	TI,		SEN(msgctl),			"msgctl"		},
[6070] = { 3,	TD,		SEN(fcntl),			"fcntl"			},
[6071] = { 2,	TD,		SEN(flock),			"flock"			},
[6072] = { 1,	TD,		SEN(fsync),			"fsync"			},
[6073] = { 1,	TD,		SEN(fdatasync),			"fdatasync"		},
[6074] = { 2,	TF,		SEN(truncate64),		"truncate"		},
[6075] = { 2,	TD,		SEN(ftruncate64),		"ftruncate"		},
[6076] = { 3,	TD,		SEN(getdents),			"getdents"		},
[6077] = { 2,	TF,		SEN(getcwd),			"getcwd"		},
[6078] = { 1,	TF,		SEN(chdir),			"chdir"			},
[6079] = { 1,	TD,		SEN(fchdir),			"fchdir"		},
[6080] = { 2,	TF,		SEN(rename),			"rename"		},
[6081] = { 2,	TF,		SEN(mkdir),			"mkdir"			},
[6082] = { 1,	TF,		SEN(rmdir),			"rmdir"			},
[6083] = { 2,	TD|TF,		SEN(creat),			"creat"			},
[6084] = { 2,	TF,		SEN(link),			"link"			},
[6085] = { 1,	TF,		SEN(unlink),			"unlink"		},
[6086] = { 2,	TF,		SEN(symlink),			"symlink"		},
[6087] = { 3,	TF,		SEN(readlink),			"readlink"		},
[6088] = { 2,	TF,		SEN(chmod),			"chmod"			},
[6089] = { 2,	TD,		SEN(fchmod),			"fchmod"		},
[6090] = { 3,	TF,		SEN(chown),			"chown"			},
[6091] = { 3,	TD,		SEN(fchown),			"fchown"		},
[6092] = { 3,	TF,		SEN(chown),			"lchown"		},
[6093] = { 1,	NF,		SEN(umask),			"umask"			},
[6094] = { 2,	0,		SEN(gettimeofday),		"gettimeofday"		},
[6095] = { 2,	0,		SEN(getrlimit),			"getrlimit"		},
[6096] = { 2,	0,		SEN(getrusage),			"getrusage"		},
[6097] = { 1,	0,		SEN(sysinfo),			"sysinfo"		},
[6098] = { 1,	0,		SEN(times),			"times"			},
[6099] = { 4,	0,		SEN(ptrace),			"ptrace"		},
[6100] = { 0,	NF,		SEN(getuid),			"getuid"		},
[6101] = { 3,	0,		SEN(syslog),			"syslog"		},
[6102] = { 0,	NF,		SEN(getgid),			"getgid"		},
[6103] = { 1,	0,		SEN(setuid),			"setuid"		},
[6104] = { 1,	0,		SEN(setgid),			"setgid"		},
[6105] = { 0,	NF,		SEN(geteuid),			"geteuid"		},
[6106] = { 0,	NF,		SEN(getegid),			"getegid"		},
[6107] = { 2,	0,		SEN(setpgid),			"setpgid"		},
[6108] = { 0,	NF,		SEN(getppid),			"getppid"		},
[6109] = { 0,	0,		SEN(getpgrp),			"getpgrp"		},
[6110] = { 0,	0,		SEN(setsid),			"setsid"		},
[6111] = { 2,	0,		SEN(setreuid),			"setreuid"		},
[6112] = { 2,	0,		SEN(setregid),			"setregid"		},
[6113] = { 2,	0,		SEN(getgroups),			"getgroups"		},
[6114] = { 2,	0,		SEN(setgroups),			"setgroups"		},
[6115] = { 3,	0,		SEN(setresuid),			"setresuid"		},
[6116] = { 3,	0,		SEN(getresuid),			"getresuid"		},
[6117] = { 3,	0,		SEN(setresgid),			"setresgid"		},
[6118] = { 3,	0,		SEN(getresgid),			"getresgid"		},
[6119] = { 1,	0,		SEN(getpgid),			"getpgid"		},
[6120] = { 1,	NF,		SEN(setfsuid),			"setfsuid"		},
[6121] = { 1,	NF,		SEN(setfsgid),			"setfsgid"		},
[6122] = { 1,	0,		SEN(getsid),			"getsid"		},
[6123] = { 2,	0,		SEN(capget),			"capget"		},
[6124] = { 2,	0,		SEN(capset),			"capset"		},
[6125] = { 2,	TS,		SEN(rt_sigpending),		"rt_sigpending"		},
[6126] = { 4,	TS,		SEN(rt_sigtimedwait),		"rt_sigtimedwait"	},
[6127] = { 3,	TS,		SEN(rt_sigqueueinfo),		"rt_sigqueueinfo"	},
[6128] = { 2,	TS,		SEN(rt_sigsuspend),		"rt_sigsuspend"		},
[6129] = { 2,	TS,		SEN(sigaltstack),		"sigaltstack"		},
[6130] = { 2,	TF,		SEN(utime),			"utime"			},
[6131] = { 3,	TF,		SEN(mknod),			"mknod"			},
[6132] = { 1,	NF,		SEN(personality),		"personality"		},
[6133] = { 2,	0,		SEN(ustat),			"ustat"			},
[6134] = { 2,	TF,		SEN(statfs),			"statfs"		},
[6135] = { 2,	TD,		SEN(fstatfs),			"fstatfs"		},
[6136] = { 3,	0,		SEN(sysfs),			"sysfs"			},
[6137] = { 2,	0,		SEN(getpriority),		"getpriority"		},
[6138] = { 3,	0,		SEN(setpriority),		"setpriority"		},
[6139] = { 2,	0,		SEN(sched_setparam),		"sched_setparam"	},
[6140] = { 2,	0,		SEN(sched_getparam),		"sched_getparam"	},
[6141] = { 3,	0,		SEN(sched_setscheduler),	"sched_setscheduler"	},
[6142] = { 1,	0,		SEN(sched_getscheduler),	"sched_getscheduler"	},
[6143] = { 1,	0,		SEN(sched_get_priority_max),	"sched_get_priority_max"},
[6144] = { 1,	0,		SEN(sched_get_priority_min),	"sched_get_priority_min"},
[6145] = { 2,	0,		SEN(sched_rr_get_interval),	"sched_rr_get_interval"	},
[6146] = { 2,	TM,		SEN(mlock),			"mlock"			},
[6147] = { 2,	TM,		SEN(munlock),			"munlock"		},
[6148] = { 1,	TM,		SEN(mlockall),			"mlockall"		},
[6149] = { 0,	TM,		SEN(munlockall),		"munlockall"		},
[6150] = { 0,	0,		SEN(vhangup),			"vhangup"		},
[6151] = { 2,	TF,		SEN(pivotroot),			"pivot_root"		},
[6152] = { 1,	0,		SEN(sysctl),			"_sysctl"		},
[6153] = { 5,	0,		SEN(prctl),			"prctl"			},
[6154] = { 1,	0,		SEN(adjtimex),			"adjtimex"		},
[6155] = { 2,	0,		SEN(setrlimit),			"setrlimit"		},
[6156] = { 1,	TF,		SEN(chroot),			"chroot"		},
[6157] = { 0,	0,		SEN(sync),			"sync"			},
[6158] = { 1,	TF,		SEN(acct),			"acct"			},
[6159] = { 2,	0,		SEN(settimeofday),		"settimeofday"		},
[6160] = { 5,	TF,		SEN(mount),			"mount"			},
[6161] = { 2,	TF,		SEN(umount2),			"umount2"		},
[6162] = { 2,	TF,		SEN(swapon),			"swapon"		},
[6163] = { 1,	TF,		SEN(swapoff),			"swapoff"		},
[6164] = { 4,	0,		SEN(reboot),			"reboot"		},
[6165] = { 2,	0,		SEN(sethostname),		"sethostname"		},
[6166] = { 2,	0,		SEN(setdomainname),		"setdomainname"		},
[6167] = { 2,	0,		SEN(create_module),		"create_module"		},
[6168] = { 3,	0,		SEN(init_module),		"init_module"		},
[6169] = { 2,	0,		SEN(delete_module),		"delete_module"		},
[6170] = { 1,	0,		SEN(get_kernel_syms),		"get_kernel_syms"	},
[6171] = { 5,	0,		SEN(query_module),		"query_module"		},
[6172] = { 4,	TF,		SEN(quotactl),			"quotactl"		},
[6173] = { 3,	0,		SEN(nfsservctl),		"nfsservctl"		},
[6174] = { 5,	TN,		SEN(getpmsg),			"getpmsg"		},
[6175] = { 5,	TN,		SEN(putpmsg),			"putpmsg"		},
[6176] = { 0,	0,		SEN(afs_syscall),		"afs_syscall"		},
[6177] = { 0,	0,		SEN(printargs),			"reserved177"		},
[6178] = { 0,	NF,		SEN(gettid),			"gettid"		},
[6179] = { 3,	TD,		SEN(readahead),			"readahead"		},
[6180] = { 5,	TF,		SEN(setxattr),			"setxattr"		},
[6181] = { 5,	TF,		SEN(setxattr),			"lsetxattr"		},
[6182] = { 5,	TD,		SEN(fsetxattr),			"fsetxattr"		},
[6183] = { 4,	TF,		SEN(getxattr),			"getxattr"		},
[6184] = { 4,	TF,		SEN(getxattr),			"lgetxattr"		},
[6185] = { 4,	TD,		SEN(fgetxattr),			"fgetxattr"		},
[6186] = { 3,	TF,		SEN(listxattr),			"listxattr"		},
[6187] = { 3,	TF,		SEN(listxattr),			"llistxattr"		},
[6188] = { 3,	TD,		SEN(flistxattr),		"flistxattr"		},
[6189] = { 2,	TF,		SEN(removexattr),		"removexattr"		},
[6190] = { 2,	TF,		SEN(removexattr),		"lremovexattr"		},
[6191] = { 2,	TD,		SEN(fremovexattr),		"fremovexattr"		},
[6192] = { 2,	TS,		SEN(kill),			"tkill"			},
[6193] = { 1,	0,		SEN(time),			"time"			},
[6194] = { 6,	0,		SEN(futex),			"futex"			},
[6195] = { 3,	0,		SEN(sched_setaffinity),		"sched_setaffinity"	},
[6196] = { 3,	0,		SEN(sched_getaffinity),		"sched_getaffinity"	},
[6197] = { 3,	0,		SEN(printargs),			"cacheflush"		},
[6198] = { 3,	0,		SEN(printargs),			"cachectl"		},
[6199] = { 4,	0,		SEN(sysmips),			"sysmips"		},
[6200] = { 2,	TM,		SEN(io_setup),			"io_setup"		},
[6201] = { 1,	TM,		SEN(io_destroy),		"io_destroy"		},
[6202] = { 5,	0,		SEN(io_getevents),		"io_getevents"		},
[6203] = { 3,	0,		SEN(io_submit),			"io_submit"		},
[6204] = { 3,	0,		SEN(io_cancel),			"io_cancel"		},
[6205] = { 1,	TP|SE,		SEN(exit),			"exit_group"		},
[6206] = { 3,	0,		SEN(lookup_dcookie),		"lookup_dcookie"	},
[6207] = { 1,	TD,		SEN(epoll_create),		"epoll_create"		},
[6208] = { 4,	TD,		SEN(epoll_ctl),			"epoll_ctl"		},
[6209] = { 4,	TD,		SEN(epoll_wait),		"epoll_wait"		},
[6210] = { 5,	TM|SI,		SEN(remap_file_pages),		"remap_file_pages"	},
[6211] = { 0,	TS,		SEN(rt_sigreturn),		"rt_sigreturn"		},
[6212] = { 3,	TD,		SEN(fcntl64),			"fcntl64"		},
[6213] = { 1,	0,		SEN(set_tid_address),		"set_tid_address"	},
[6214] = { 0,	0,		SEN(restart_syscall),		"restart_syscall"	},
[6215] = { 4,	TI,		SEN(semtimedop),		"semtimedop"		},
[6216] = { 4,	TD,		SEN(fadvise64_64),		"fadvise64"		},
[6217] = { 3,	TF,		SEN(statfs64),			"statfs64"		},
[6218] = { 3,	TD,		SEN(fstatfs64),			"fstatfs64"		},
[6219] = { 4,	TD|TN,		SEN(sendfile64),		"sendfile64"		},
[6220] = { 3,	0,		SEN(timer_create),		"timer_create"		},
[6221] = { 4,	0,		SEN(timer_settime),		"timer_settime"		},
[6222] = { 2,	0,		SEN(timer_gettime),		"timer_gettime"		},
[6223] = { 1,	0,		SEN(timer_getoverrun),		"timer_getoverrun"	},
[6224] = { 1,	0,		SEN(timer_delete),		"timer_delete"		},
[6225] = { 2,	0,		SEN(clock_settime),		"clock_settime"		},
[6226] = { 2,	0,		SEN(clock_gettime),		"clock_gettime"		},
[6227] = { 2,	0,		SEN(clock_getres),		"clock_getres"		},
[6228] = { 4,	0,		SEN(clock_nanosleep),		"clock_nanosleep"	},
[6229] = { 3,	TS,		SEN(tgkill),			"tgkill"		},
[6230] = { 2,	TF,		SEN(utimes),			"utimes"		},
[6231] = { 6,	TM,		SEN(mbind),			"mbind"			},
[6232] = { 5,	TM,		SEN(get_mempolicy),		"get_mempolicy"		},
[6233] = { 3,	TM,		SEN(set_mempolicy),		"set_mempolicy"		},
[6234] = { 4,	0,		SEN(mq_open),			"mq_open"		},
[6235] = { 1,	0,		SEN(mq_unlink),			"mq_unlink"		},
[6236] = { 5,	0,		SEN(mq_timedsend),		"mq_timedsend"		},
[6237] = { 5,	0,		SEN(mq_timedreceive),		"mq_timedreceive"	},
[6238] = { 2,	0,		SEN(mq_notify),			"mq_notify"		},
[6239] = { 3,	0,		SEN(mq_getsetattr),		"mq_getsetattr"		},
[6240] = { 5,	0,		SEN(vserver),			"vserver"		},
[6241] = { 5,	TP,		SEN(waitid),			"waitid"		},
[6242] = { },
[6243] = { 5,	0,		SEN(add_key),			"add_key"		},
[6244] = { 4,	0,		SEN(request_key),		"request_key"		},
[6245] = { 5,	0,		SEN(keyctl),			"keyctl"		},
[6246] = { 1,	0,		SEN(set_thread_area),		"set_thread_area"	},
[6247] = { 0,	TD,		SEN(inotify_init),		"inotify_init"		},
[6248] = { 3,	TD,		SEN(inotify_add_watch),		"inotify_add_watch"	},
[6249] = { 2,	TD,		SEN(inotify_rm_watch),		"inotify_rm_watch"	},
[6250] = { 4,	TM,		SEN(migrate_pages),		"migrate_pages"		},
[6251] = { 4,	TD|TF,		SEN(openat),			"openat"		},
[6252] = { 3,	TD|TF,		SEN(mkdirat),			"mkdirat"		},
[6253] = { 4,	TD|TF,		SEN(mknodat),			"mknodat"		},
[6254] = { 5,	TD|TF,		SEN(fchownat),			"fchownat"		},
[6255] = { 3,	TD|TF,		SEN(futimesat),			"futimesat"		},
[6256] = { 4,	TD|TF,		SEN(newfstatat),		"newfstatat"		},
[6257] = { 3,	TD|TF,		SEN(unlinkat),			"unlinkat"		},
[6258] = { 4,	TD|TF,		SEN(renameat),			"renameat"		},
[6259] = { 5,	TD|TF,		SEN(linkat),			"linkat"		},
[6260] = { 3,	TD|TF,		SEN(symlinkat),			"symlinkat"		},
[6261] = { 4,	TD|TF,		SEN(readlinkat),		"readlinkat"		},
[6262] = { 3,	TD|TF,		SEN(fchmodat),			"fchmodat"		},
[6263] = { 3,	TD|TF,		SEN(faccessat),			"faccessat"		},
[6264] = { 6,	TD,		SEN(pselect6),			"pselect6"		},
[6265] = { 5,	TD,		SEN(ppoll),			"ppoll"			},
[6266] = { 1,	TP,		SEN(unshare),			"unshare"		},
[6267] = { 6,	TD,		SEN(splice),			"splice"		},
[6268] = { 4,	TD,		SEN(sync_file_range),		"sync_file_range"	},
[6269] = { 4,	TD,		SEN(tee),			"tee"			},
[6270] = { 4,	TD,		SEN(vmsplice),			"vmsplice"		},
[6271] = { 6,	TM,		SEN(move_pages),		"move_pages"		},
[6272] = { 2,	0,		SEN(set_robust_list),		"set_robust_list"	},
[6273] = { 3,	0,		SEN(get_robust_list),		"get_robust_list"	},
[6274] = { 4,	0,		SEN(kexec_load),		"kexec_load"		},
[6275] = { 3,	0,		SEN(getcpu),			"getcpu"		},
[6276] = { 6,	TD,		SEN(epoll_pwait),		"epoll_pwait"		},
[6277] = { 3,	0,		SEN(ioprio_set),		"ioprio_set"		},
[6278] = { 2,	0,		SEN(ioprio_get),		"ioprio_get"		},
[6279] = { 4,	TD|TF,		SEN(utimensat),			"utimensat"		},
[6280] = { 3,	TD|TS,		SEN(signalfd),			"signalfd"		},
[6281] = { 4,	TD,		SEN(timerfd),			"timerfd"		},
[6282] = { 1,	TD,		SEN(eventfd),			"eventfd"		},
[6283] = { 4,	TD,		SEN(fallocate),			"fallocate"		},
[6284] = { 2,	TD,		SEN(timerfd_create),		"timerfd_create"	},
[6285] = { 2,	TD,		SEN(timerfd_gettime),		"timerfd_gettime"	},
[6286] = { 4,	TD,		SEN(timerfd_settime),		"timerfd_settime"	},
[6287] = { 4,	TD|TS,		SEN(signalfd4),			"signalfd4"		},
[6288] = { 2,	TD,		SEN(eventfd2),			"eventfd2"		},
[6289] = { 1,	TD,		SEN(epoll_create1),		"epoll_create1"		},
[6290] = { 3,	TD,		SEN(dup3),			"dup3"			},
[6291] = { 2,	TD,		SEN(pipe2),			"pipe2"			},
[6292] = { 1,	TD,		SEN(inotify_init1),		"inotify_init1"		},
[6293] = { 4,	TD,		SEN(preadv),			"preadv"		},
[6294] = { 4,	TD,		SEN(pwritev),			"pwritev"		},
[6295] = { 4,	TP|TS,		SEN(rt_tgsigqueueinfo),		"rt_tgsigqueueinfo"	},
[6296] = { 5,	TD,		SEN(perf_event_open),		"perf_event_open"	},
[6297] = { 4,	TN,		SEN(accept4),			"accept4"		},
[6298] = { 5,	TN,		SEN(recvmmsg),			"recvmmsg"		},
[6299] = { 3,	TD,		SEN(getdents64),		"getdents64"		},
[6300] = { 2,	TD,		SEN(fanotify_init),		"fanotify_init"		},
[6301] = { 5,	TD|TF,		SEN(fanotify_mark),		"fanotify_mark"		},
[6302] = { 4,	0,		SEN(prlimit64),			"prlimit64"		},
[6303] = { 5,	TD|TF,		SEN(name_to_handle_at),		"name_to_handle_at"	},
[6304] = { 3,	TD,		SEN(open_by_handle_at),		"open_by_handle_at"	},
[6305] = { 2,	0,		SEN(clock_adjtime),		"clock_adjtime"		},
[6306] = { 1,	TD,		SEN(syncfs),			"syncfs"		},
[6307] = { 4,	TN,		SEN(sendmmsg),			"sendmmsg"		},
[6308] = { 2,	TD,		SEN(setns),			"setns"			},
[6309] = { 6,	0,		SEN(process_vm_readv),		"process_vm_readv"	},
[6310] = { 6,	0,		SEN(process_vm_writev),		"process_vm_writev"	},
[6311] = { 5,	0,		SEN(kcmp),			"kcmp"			},
[6312] = { 3,	TD,		SEN(finit_module),		"finit_module"		},
[6313] = { 3,	0,		SEN(sched_setattr),		"sched_setattr"		},
[6314] = { 4,	0,		SEN(sched_getattr),		"sched_getattr"		},
[6315] = { 5,	TD|TF,		SEN(renameat2),			"renameat2"		},
[6316] = { 3,	0,		SEN(seccomp),			"seccomp",		},
[6317] = { 3,	0,		SEN(getrandom),			"getrandom",		},
[6318] = { 2,	TD,		SEN(memfd_create),		"memfd_create",		},
[6319] = { 3,	TD,		SEN(bpf),			"bpf",			},
[6320] = { 5,	TD|TF|TP|SE|SI,	SEN(execveat),			"execveat",		},
[6321] = { 1,	TD,		SEN(userfaultfd),		"userfaultfd",		},
[6322] = { 2,	0,		SEN(membarrier),		"membarrier",		},
[6323] = { 3,	TM,		SEN(mlock2),			"mlock2"		},
[6324] = { 6,	TD,		SEN(copy_file_range),		"copy_file_range"	},
[6325] = { 6,	TD,		SEN(preadv2),			"preadv2"		},
[6326] = { 6,	TD,		SEN(pwritev2),			"pwritev2"		},

# define SYS_socket_subcall      6400
# include "subcall.h"

#else

# include "syscallent-n32-stub.h"

#endif
