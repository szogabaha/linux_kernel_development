#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>

int main()
{
    long int ret = syscall(548);
    printf("System call returned %ld\n", ret);
    return 0;
}