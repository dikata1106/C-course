#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();

    switch (pid){
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
            break;
        case 0:
            exit(EXIT_SUCCESS);
            break;
    }
    int status;
    if (-1 == wait(&status)){
        perror("wait");
        exit(EXIT_FAILURE);
    }
    printf("%d\n", pid);
    printf("%d\n", WEXITSTATUS(status));
    return EXIT_SUCCESS;
}