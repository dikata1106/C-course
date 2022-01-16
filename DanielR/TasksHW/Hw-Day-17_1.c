#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {

    int pfd[2];
    
    pipe(pfd);

    switch (fork()) {
        case -1:
            perror("fork1");
            break;
        case 0:
            close(STDOUT_FILENO);
            dup(pfd[1]);
            close(pfd[0]);
            close(pfd[1]);
            int start = 1, end = argc/2, i, sum = 0;
            for (i = start; i<end; i++) {
                sum += atoi(argv[i]);
            }
            printf("%d", sum);
            break;
        default:
            break;
    }

    switch (fork()) {
        case -1:
            perror("fork2");
            break;
        case 0:
            close(STDIN_FILENO);
            dup(pfd[0]);
            close(pfd[0]);
            close(pfd[1]);
            int start = argc/2, end = argc, i, sum = 0, sumTot;
            for (i = start; i<end; i++) {
                sum += atoi(argv[i]);
            }
            scanf("%d", &sumTot);
            sumTot += sum;
            printf("Sum: %d\n", sumTot);
            break;
        default:
            break;
    }

    close(pfd[0]);
    close(pfd[1]);

    while (wait(NULL) != -1);

    exit(EXIT_SUCCESS);
}

// // EXTENDED
// int main(int argc, char **argv) {

//     int pfd[2];
    
//     if (pipe(pfd) == -1)
//         perror("pipe");

//     switch (fork()) {
//         case -1:
//             perror("fork1");
//             break;
//         case 0:
//             if (close(STDOUT_FILENO) == -1)
//                 perror("close1");
//             if (dup(pfd[1]) != STDOUT_FILENO)
//                 perror("dup1");
//             if (close(pfd[0]) == -1 || close(pfd[1]) == -1)
//                 perror("close2");
//             int start = 1, end = argc/2, i, sum = 0;
//             for (i = start; i<end; i++) {
//                 sum += atoi(argv[i]);
//             }
//             printf("%d", sum);
//             break;
//         default:
//             break;
//     }

//     switch (fork()) {
//         case -1:
//             perror("fork2");
//             break;
//         case 0:
//             if (close(STDIN_FILENO) == -1)
//                 perror("close3");
//             if (dup(pfd[0]) != STDIN_FILENO)
//                 perror("dup2");
//             if (close(pfd[0]) == -1 || close(pfd[1]) == -1)
//                 perror("close4");
//             int start = argc/2, end = argc, i, sum = 0, sumTot;
//             for (i = start; i<end; i++) {
//                 sum += atoi(argv[i]);
//             }
//             scanf("%d", &sumTot);
//             sumTot += sum;
//             printf("Sum: %d\n", sumTot);
//             break;
//         default:
//             break;
//     }

//     if (close(pfd[0]) == -1 || close(pfd[1]) == -1)
//         perror("close5");

//     while (wait(NULL) != -1);

//     exit(EXIT_SUCCESS);
// }