#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

double getTime(void) {
    struct timeval curTime;
    gettimeofday(&curTime, NULL);
    return (double)curTime.tv_usec/1000000 + (double)curTime.tv_sec;
}

int main(int argc, char **argv) {

    int pfd[2], n, ofd, ifd;
    pipe(pfd);
    char strG[200], strE[200];
    double startMS;
    if (argc != 4) {
        fprintf(stderr, "Use: %s testedExe sampleInputFile sampleOutputFile", argv[0]);
        exit(EXIT_FAILURE);
    }
    startMS = getTime();
    switch (fork()) {
        case -1:
            perror("fork");
            exit(EXIT_FAILURE);
            break;
        case 0:
            ifd = open(argv[2], O_RDONLY);
            if(ifd == -1) {
                perror("open1");
                exit(EXIT_FAILURE);
            }
            dup2(ifd, STDIN_FILENO);
            close(ifd);
            dup2(pfd[1], STDOUT_FILENO);
            close(pfd[1]);
            close(pfd[0]);
            execl(argv[1], argv[1], NULL);
            perror("exec");
            exit(EXIT_FAILURE);
            break;
        default:
            wait(NULL);
            printf("Execution time:\t%lf\n", getTime() - startMS);
            dup2(pfd[0], STDIN_FILENO);
            close(pfd[0]);
            close(pfd[1]);
            n = read(STDIN_FILENO, strG, 200);
            strG[n++] = '\0';
            ofd = open(argv[3], O_RDONLY);
            if(ofd == -1) {
                perror("open2");
                exit(EXIT_FAILURE);
            }
            n = read(ofd, strE, 200);
            strE[n++] = '\0';
            close(ofd);
            printf("Got:\t\t%s", strG);
            printf("Expected:\t%s", strE);
            if (strcmp(strE, strG) == 0)
                printf("CORRECT PROGRAM\n");
            else
                printf("WRONG PROGRAM\n");
            break;
    }
    
    exit(EXIT_SUCCESS);
}