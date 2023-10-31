# System calls - Process info

In this work I added a system call to the kernel that collects process information. The following information is collected: state, nice, pid, parent\_pid, youngest\_child\_pid, start\_time, user\_time, sys\_time, uid, comm[]. Careful attention is paid to check validity of arguments passed by a caller.

## Files
- The detailed.pdf contains a detailed description on the steps.
- The get_process_info contains the newly implemented code.
- The task2.c is a user-space example code to test if the syscall works.
- The other files are part of the kernel source code. These are the ones that slightly needed to be modified in order to add the syscall to the kernel. 

## Method
1. the current process' information can be accessed via the get_current() function, already available in the kernel source. The "current" macro encapsulates it.
2. The processes are represented as a "task_struct" structure. The implementation is in the linux/sched.h file. It contains a lot more information then what the syscall collects. For some values, there are helper functions (ex.: list_first_entry, get_task_comm etc.).
3. If I include the "linux/sched.h" at the syscall implementation, both the previously mentioned struct and the "current" macro becomes available. I used that.
4. safe copy from kernel space to user space: copy_to_user. There is a copy_from_user function as well, but it wasn't needed here.

