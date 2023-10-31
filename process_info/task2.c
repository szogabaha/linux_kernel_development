#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <linux/unistd.h> // For syscall numbers

struct prinfo {
    long state;
    long nice;
    int pid;
    int parent_pid;
    int youngest_child_pid;
    unsigned long start_time;
    long user_time;
    long sys_time;
    long uid;
    char comm[16];
};

void processAndPrintInfo() {
    struct prinfo process_info;
    long result = syscall(549, &process_info);

    if (result == 0) {
        // Syscall succeeded, print the process information
        printf("State: %ld\n", process_info.state);
        printf("Nice: %ld\n", process_info.nice);
        printf("PID: %d\n", process_info.pid);
        printf("Parent PID: %d\n", process_info.parent_pid);
        printf("Youngest Child PID: %d\n", process_info.youngest_child_pid);
        printf("Start Time: %lu\n", process_info.start_time);
        printf("User Time: %ld\n", process_info.user_time);
        printf("Sys Time: %ld\n", process_info.sys_time);
        printf("UID: %ld\n", process_info.uid);
        printf("Comm: %s\n", process_info.comm);
    } else {
        // Syscall failed, print an error message
        perror("Syscall failed");
    }
    printf("\n\n");
}

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        int k = 0;
        for (int i = 0; i < 100000000; i++) {
            k = i / 2;
        }
        processAndPrintInfo();
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
	processAndPrintInfo();
        int status;
        waitpid(pid, &status, 0);
    }

    return 0;
}

