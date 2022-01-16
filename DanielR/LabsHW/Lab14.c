// TODO: read() / write() error control

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 512

int readLine(int fr, char *line) {
    int i = 0;
    while(read(fr, &line[i], sizeof(char)) == 1 && line[i++] != '\n');
    line[i] = '\0';
    return strlen(line);
}

int main(int argc, char **argv) {

    char errmsg[BUFSIZE], line[BUFSIZE], name[8];
    int i, N, fr, *fw;

    if (argc > 3 || argc == 1) {
        // strcpy(errmsg, "Invalid number of arguments\n");
        sprintf(errmsg, "Invalid number of arguments\nUse: %s [filename] N\n", argv[0]);
        write(STDERR_FILENO, errmsg, strlen(errmsg));
        exit(EXIT_FAILURE);
    }

    if (2 == argc) {
        N = atoi(argv[1]);
        fr = STDIN_FILENO;
    } else {
        N = atoi(argv[2]);
        fr = open(argv[1], O_RDONLY);
        if (-1 == fr) {
            perror("Open fileread");
            exit(EXIT_FAILURE);
        }
    }

    if (N) {
        fw = (int*)malloc(N*sizeof(int));
        for (i=0; i<N; i++) {
            sprintf(name, "log%d", i+1);
            fw[i] = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0666);
            if (-1 == fw[i]) {
                perror("Open filewrite");
                close(fr);
                for (i-=1; i>=0; i--) {
                    close(fw[i]);
                }
                exit(EXIT_FAILURE);
            }
        }
    } else {
        fw = (int*)malloc(sizeof(int));
        fw[0] = STDOUT_FILENO;
    }
    i = 0;
    while (readLine(fr, line)) {
        write(fw[i], line, strlen(line));
        if(++i == N) {
            i = 0;
        }
    }
    close(fr);
    for (i=0; i<N; i++) {
        close(fw[i]);
    }
    free(fw);
    exit(EXIT_SUCCESS);
}