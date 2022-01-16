#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int fork_exec(const char* command){
    pid_t pid = fork();
    if (pid == -1){
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0){
        if (-1 == execlp(command, command, NULL)){
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }
    int status;
    wait(&status);
    return WEXITSTATUS(status);
}

int main(int argc, char **argv){
    if (argc != 3){
        exit(EXIT_FAILURE);
    }
    int exitStatus = fork_exec(argv[1]);
    if (EXIT_SUCCESS != exitStatus){
        return EXIT_FAILURE;
    }
    exitStatus = fork_exec(argv[2]);
    return exitStatus;
}