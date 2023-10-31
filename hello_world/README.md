# System calls - Hello World!

This work shows how to add a simple system call to a kernel. The function of the call is to print a message with a KERN\_EMERG priority. I also added a small user-level snippet to try out the system call.

## Method

1. Create a new directory at root. This contains the implementation of the new function (hello)
2. Implement the system call and
3. Extend the obj-y value in the Kbuild file and  write a Makefile under the hello dir
4. Add the system call to the system call table (here arch/x86/entry/syscalls/syscall_64.tbl). The identifier of the function: 548
5. Add the system call declaration to the system header (include/linux/syscalls.h)
6. Compile, install the kernel.


## Resources
- https://medium.com/anubhav-shrimal/adding-a-hello-world-system-call-to-linux-kernel-dad32875872
- https://redirect.cs.umbc.edu/courses/undergraduate/421/spring21/docs/project0.html
- https://www.kernel.org/doc/html/next/core-api/printk-basics.html
