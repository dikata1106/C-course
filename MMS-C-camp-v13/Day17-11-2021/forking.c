#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();
    if (pid == -1){
        perror("Forking");
        exit(EXIT_FAILURE);
    }
    if (pid == 0){
        // child process
        sleep(2);
        printf("I'm child process!\n");
        printf("(child) My PID is: %d\n", getpid());
        printf("(child) My PPID is: %d\n", getppid());
    } else {
        // parent process
        printf("I'm parent process!\n");
        printf("(parent) My PID is %d\n", getpid());
        printf("(parent)My PPID is %d\n", getppid());
        printf("(parent) My child PID is %d\n", pid);
        wait(NULL);
    }
    return EXIT_SUCCESS;
}