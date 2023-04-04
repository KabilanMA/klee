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
    "klee_overshift_check"
    };

static const std::unordered_set<std::string> ExternalFiles {
"./include/bits/sigset.h",
"./include/sys/sysmacros.h",
"libc/misc/ctype/ctype.c",
"libc/misc/error/error.c",
"libc/misc/gnu/obstack.c",
"libc/misc/internals/__h_errno_location.c",
"libc/misc/internals/__uClibc_main.c",
"libc/misc/internals/tempname.c",
"libc/misc/locale/locale.c",
"libc/misc/utmp/utent.c",
"libc/misc/wchar/wchar.c",
"libc/misc/wctype/_wctype.c",
"libc/signal/raise.c",
"libc/signal/sigaction.c",
"libc/signal/sigblock.c",
"libc/signal/siggetmask.c",
"libc/signal/sigset-cvt-mask.h",
"libc/stdio/_READ.c",
"libc/stdio/_WRITE.c",
"libc/stdio/__fpending.c",
"libc/stdio/_adjust_pos.c",
"libc/stdio/_cs_funcs.c",
"libc/stdio/_fopen.c",
"libc/stdio/_fpmaxtostr.c",
"libc/stdio/_fwrite.c",
"libc/stdio/_load_inttype.c",
"libc/stdio/_rfill.c",
"libc/stdio/_stdio.c",
"libc/stdio/_store_inttype.c",
"libc/stdio/_trans2r.c",
"libc/stdio/_trans2w.c",
"libc/stdio/_uintmaxtostr.c",
"libc/stdio/_vfprintf.c",
"libc/stdio/_wcommit.c",
"libc/stdio/fclose.c",
"libc/stdio/ferror.c",
"libc/stdio/fflush.c",
"libc/stdio/fgetc.c",
"libc/stdio/fopen.c",
"libc/stdio/fprintf.c",
"libc/stdio/fputc.c",
"libc/stdio/fputs.c",
"libc/stdio/fseeko.c",
"libc/stdio/fwrite.c",
"libc/stdio/getchar.c",
"libc/stdio/gets.c",
"libc/stdio/putchar.c",
"libc/stdio/snprintf.c",
"libc/stdio/sprintf.c",
"libc/stdio/tmpnam.c",
"libc/stdio/vsnprintf.c",
"libc/stdlib/_atexit.c",
"libc/stdlib/getenv.c",
"libc/stdlib/stdlib.c",
"libc/stdlib/mktemp.c",
"libc/stdlib/realpath.c",
"libc/string/__xpg_strerror_r.c",
"libc/string/memchr.c",
"libc/string/memcmp.c",
"libc/string/memcpy.c",
"libc/string/memmove.c",
"libc/string/mempcpy.c",
"libc/string/memrchr.c",
"libc/string/memset.c",
"libc/string/stpcpy.c",
"libc/string/strchr.c",
"libc/string/strcmp.c",
"libc/string/strcpy.c",
"libc/string/strdup.c",
"libc/string/strerror.c",
"libc/string/strlen.c",
"libc/string/strncmp.c",
"libc/string/strnlen.c",
"libc/string/strpbrk.c",
"libc/string/strrchr.c",
"libc/string/strspn.c",
"libc/string/strtok_r.c",
"libc/termios/isatty.c",
"libc/termios/tcgetattr.c",
"libc/unistd/getopt.c",
"runtime/Intrinsic/klee_div_zero_check.c",
"runtime/Intrinsic/klee_overshift_check.c",
"runtime/Intrinsic/klee_range.c",
"runtime/POSIX/fd.c",
"runtime/POSIX/fd_32.c",
"runtime/POSIX/fd_64.c",
"runtime/POSIX/fd_init.c",
"runtime/POSIX/illegal.c",
"runtime/POSIX/klee_init_env.c",
"runtime/POSIX/stubs.c"
};

#endif // KLEE_EXTERNALFUNCTIONS_H