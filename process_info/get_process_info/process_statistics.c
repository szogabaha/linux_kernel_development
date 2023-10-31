#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>
#include <linux/cred.h> //go use current_uid
#include <linux/sched.h> //to get the "current"
#include "prinfo.h"

SYSCALL_DEFINE1(get_process_statistics, struct prinfo*, info) {
    struct prinfo process_info;

    // Fill the struct with process information
    process_info.state = current->__state;
    process_info.nice = task_nice(current);
    process_info.pid = current->pid;
    process_info.parent_pid = current->real_parent->pid;

    if (!list_empty(&current->children)) {
        process_info.youngest_child_pid = list_first_entry(&current->children, struct task_struct, sibling)->pid;
    } else {
        process_info.youngest_child_pid = -1;
    }

    process_info.start_time = current->start_time;
    process_info.user_time = current->utime;
    process_info.sys_time = current->stime;
    process_info.uid = from_kuid(&init_user_ns, current_uid());
    get_task_comm(process_info.comm, current);

    // Copy the struct to user space
    if (copy_to_user(info, &process_info, sizeof(struct prinfo)) != 0) {
        return -EFAULT; // Error handling for copy_to_user failure
    }

    return 0;
}
