#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE0(hello) {
    printk(KERN_EMERG "Gabor Szolnok - 61247086S\n");
    return 0;
}
