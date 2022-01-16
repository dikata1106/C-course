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
    int n = -1;
    unsigned cntRows = 0;
    while (lseek(fd, n, SEEK_END) != -1){
        read(fd, &ch, 1);
        write(STDOUT_FILENO, &ch, 1);
        if (ch == '\n' && ++cntRows == rows){
            break;
        }
        n--;
    }

    if (argc != 1)
    if (close(fd) == -1){
        perror("Closing");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}