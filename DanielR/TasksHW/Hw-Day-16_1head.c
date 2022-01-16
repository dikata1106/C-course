#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


int main(int argc, char **argv){
    if (argc != 1 && argc != 2 && argc != 3){
        fprintf(stderr, "Invalid input arguments!\n");
        exit(EXIT_FAILURE);
    }
    char filename[200];
    int rows;
    int fd;
    if (3 == argc){
        strcpy(filename, argv[2]);
        fd = open(filename, O_RDONLY);
        rows = atoi(argv[1]);
    } else if (2 == argc){
        strcpy(filename, argv[1]);
        fd = open(filename, O_RDONLY);
        rows = 10;
    } else {
        fd = STDIN_FILENO;
        rows = 10;
    }
    if (-1 == fd){
        perror("Opening");
        exit(EXIT_FAILURE);
    }

    char ch;
    int n;
    unsigned cntRows = 0;
    while (n = read(fd, &ch, 1)){
        if (-1 == n){
            perror("Reading");
            exit(EXIT_FAILURE);
        }
        if(-1 == write(STDOUT_FILENO, &ch, 1)){
            perror("Reading");
            exit(EXIT_FAILURE);
        }
        if (ch == '\n' && ++cntRows == rows){
            break;
        }
    }

    if (argc != 1)
    if (close(fd) == -1){
        perror("Closing");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}