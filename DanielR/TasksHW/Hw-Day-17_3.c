#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

void main(int argc, char **argv) {
    
    int status;

    if (argc != 3) {
        fprintf(stderr, "Wrong number of arguments\nUse: %s cmd1 cmd2", argv[0]);
        exit(EXIT_FAILURE);
    }

    switch (fork())
    {
    case -1:    // error
        perror("fork");
        exit(EXIT_FAILURE);
    case 0: // child
        execlp(argv[1], argv[1], NULL);
        exit(EXIT_FAILURE);
        break;
    default:    // parent
        wait(&status);
        break;
    }
    // printf("%d\n", status);
    if (status) {   // cmd1 failed
        switch (fork())
        {
        case -1:    // error
            perror("fork");
            exit(EXIT_FAILURE);
        case 0: // child
            execlp(argv[2], argv[2], NULL);
            exit(EXIT_FAILURE);
            break;
        default:    // parent
            wait(&status);
            break;
        }
    } else {    // cmd1 didnt failed and returned 0
        exit(EXIT_SUCCESS);
    }
    // printf("%d\n", status);

    exit(EXIT_FAILURE);
}