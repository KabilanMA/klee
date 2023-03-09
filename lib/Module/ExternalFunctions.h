#ifndef KLEE_EXTERNALFUNCTIONS_H
#define KLEE_EXTERNALFUNCTIONS_H
#include <unordered_set>

static const std::unordered_set<std::string> ExternalFuncs{
    "__uClibc_init",
    "__uClibc_fini",
    "__uClibc_main",
    "__check_suid",
    "__check_one_fd",
    "gnu_dev_makedev.127",
    "siggetmask",
    "__fpending",
    "gets",
    "tmpnam",
    "mktemp",
    "access",
    "__get_sym_file",
    "__concretize_string",
    "__concretize_ptr",
    "getcwd",
    "__concretize_size",
    "umask",
    "__fd_open",
    "has_permission",
    "__fd_openat",
    "__get_file",
    "utimes",
    "futimesat",
    "close",
    "read",
    "write",
    "__fd_lseek",
    "__fd_stat",
    "fstatat",
    "__fd_lstat",
    "chdir",
    "fchdir",
    "chmod",
    "__df_chmod",
    "fchmod",
    "chown",
    "__df_chown",
    "fchown",
    "lchown",
    "__fd_fstat",
    "__fd_ftruncate",
    "__fd_getdents",
    "ioctl",
    "fcntl",
    "__fd_statfs",
    "fstatfs",
    "fsync",
    "dup2",
    "dup",
    "rmdir",
    "unlink",
    "unlinkat",
    "readlink",
    "select",
    "chroot",
    "open",
    "openat",
    "lseek",
    "__xstat",
    "__stat64_to_stat",
    "stat",
    "__lxstat",
    "lstat",
    "__fxstat",
    "fstat",
    "ftruncate",
    "statfs",
    "getdents",
    "klee_init_env",
    "__streq",
    "__emit_error",
    "__str_to_int",
    "__get_sym_str",
    "__add_arg",
    "__isprint",
    "__user_main",
    "__h_errno_location",
    "___path_search",
    "direxists",
    "__gen_tempname",
    "fillrand",
    "brain_damaged_fillrand",
    "_locale_set_l",
    "init_cur_collate",
    "_locale_init_l",
    "_locale_init",
    "sigblock",
    "sigset_set_old_mask",
    "sigset_get_old_mask",
    "_stdio_term",
    "_stdio_init",
    "getchar_unlocked",
    "exit",
    "memcpy",
    "memset",
    "strrchr",
    // "__klee_posix_wrapped_main",
    "klee_init_fds",
    "__create_new_dfile",
    "__sym_uint32",
    "__syscall_rt_sigaction",
    "sigaction",
    "sigprocmask",
    "fdatasync",
    "sync",
    "__socketcall",
    "_IO_getc",
    "_IO_putc",
    "mkdir",
    "mkfifo",
    "mknod",
    "pipe",
    "link",
    "symlink",
    "rename",
    "nanosleep",
    "clock_gettime",
    "clock_settime",
    "time",
    "times",
    "getutxent",
    "setutxent",
    "endutxent",
    "utmpxname",
    "euidaccess",
    "eaccess",
    "group_member",
    "utime",
    "futimes",
    "strverscmp",
    "gnu_dev_major",
    "gnu_dev_minor",
    "gnu_dev_makedev",
    "canonicalize_file_name",
    "getloadavg",
    "wait",
    "wait3",
    "wait4",
    "waitpid",
    "waitid",
    "mount",
    "umount",
    "umount2",
    "swapon",
    "swapoff",
    "setgid",
    "setgroups",
    "sethostname",
    "setpgid",
    "setpgrp",
    "setpriority",
    "setresgid",
    "setresuid",
    "setrlimit",
    "setrlimit64",
    "setsid",
    "settimeofday",
    "setuid",
    "reboot",
    "mlock",
    "munlock",
    "pause",
    "readahead",
    "mmap",
    "mmap64",
    "munmap",
    "__locale_mbrtowc_l",
    "__raise",
    "__libc_sigaction",
    "__sigismember",
    "__sigaddset",
    "__sigdelset",
    "__stdio_wcommit",
    "__fgetc_unlocked",
    "sprintf",
    "strcmp",
    "strlen",
    "strncmp",
    "isatty",
    "klee_range",
    "open64",
    "openat64",
    "lseek64",
    "__xstat64",
    "stat64",
    "__lxstat64",
    "lstat64",
    "__fxstat64",
    "fstat64",
    "ftruncate64",
    "statfs64",
    "getdents64",
    "kill",
    "_setjmp",
    "longjmp",
    "execl",
    "execlp",
    "execle",
    "execv",
    "execvp",
    "execve",
    "fork",
    "vfork",
    "setutent",
    "__setutent",
    "endutent",
    "getutent",
    "__getutent",
    "getutid",
    "__getutid",
    "getutline",
    "pututline",
    "utmpname",
    "_wchar_utf8sntowcs",
    "__stdio_READ",
    "__stdio_WRITE",
    "__stdio_rfill",
    "__stdio_trans2r_o",
    "fflush_unlocked",
    "__fputc_unlocked",
    "vsnprintf",
    "realpath",
    "tcgetattr",
    "__stdio_trans2w_o",
    "vfprintf",
    "_do_one_spec",
    "_fp_out_narrow",
    "_charpad",
    "memmove",
    "mempcpy",
    "strcpy",
    "strdup",
    "wcrtomb",
    "wcsrtombs",
    "_fpmaxtostr",
    "__stdio_fwrite",
    "_load_inttype",
    "_ppfs_init",
    "_ppfs_parsespec",
    "_is_equal_or_bigger_arg",
    "_promoted_size",
    "_ppfs_prepargs",
    "_ppfs_setargs",
    "_store_inttype",
    "_uintmaxtostr",
    "fputs_unlocked",
    "fseek",
    "strnlen",
    "__ctype_b_loc",
    "mbsrtowcs",
    "wcsnrtombs",
    "fseeko64",
    "fwrite_unlocked",
    "memchr",
    "memrchr",
    "_wchar_wcsntoutf8s",
    "mbsnrtowcs",
    "__stdio_adjust_position",
    "__stdio_seek",
    "klee_div_zero_check",
    "klee_overshift_check"};
#endif