#include <linux/syscalls.h>

#ifndef PRINFO_H
#define PRINFO_H
struct prinfo {
    long state; /* current state of process */
    long nice; /* process nice value */
    pid_t pid; /* process id */
    pid_t parent_pid; /* process id of parent */
    pid_t youngest_child_pid; /* pid of youngest child */
    unsigned long start_time; /* process start time */
    long user_time; /* CPU time spent in user mode */
    long sys_time; /* CPU time spent in system mode */
    long uid; /* user id of process owner */
    char comm[16]; /* name of program executed */
};

#endif  //PRINFO_H
