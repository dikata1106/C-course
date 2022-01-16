#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void handle_sigusr(int sig) {
    printf("(HINT) Remember that multiplication  is repetitive addition!\n");
}

int main(int argc, char* argv[]) {
    pid_t pid = fork();
    if (pid == -1) {
        return 1;
    }
    
    if (pid == 0) {
        
        sleep(5);
        kill(getppid(), SIGUSR1);
    } else {
        struct sigaction sa;
        sa.sa_flags = SA_RESTART;
        sa.sa_handler = &handle_sigusr;
        sigaction(SIGUSR1, &sa, NULL);
        int x;
        printf("What is the result of 3 x 5?: ");
        scanf("%d", &x);
        if (x == 15) {
            printf("Right!\n");
        } else {
            printf("Wrong\n");
        }
        kill(pid, SIGTERM);
        wait(NULL);
    }
    return 0;
}