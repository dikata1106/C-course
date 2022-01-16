#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "Invalid input arguments\n");
        exit(EXIT_SUCCESS);
    }
    pid_t pid = fork();
    if (pid == 0){
        if (-1 == execvp(argv[1], argv + 1)){
            exit(EXIT_FAILURE);
        }
    } else {
        int status;
        wait(&status);
        printf("\nExit status: %d\n", WEXITSTATUS(status));
    }    
    return EXIT_SUCCESS;
}