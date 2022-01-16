#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    pid_t pid = fork();
    if (pid == 0){
        if (-1 == execlp("ls", "ls", "-l", NULL)){
            perror("exec");
            exit(EXIT_FAILURE);
        }
    } else {
        wait(NULL);
        printf("Hello!\n");
    }
    return EXIT_SUCCESS;
}