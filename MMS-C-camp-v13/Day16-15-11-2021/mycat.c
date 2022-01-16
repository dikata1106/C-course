#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char **argv){
    if (argc != 2){
        fprintf(stderr, "Invalid input arguments!\n");
        exit(EXIT_FAILURE);
    }
    int fd = open(argv[1], O_RDONLY);
    if (-1 == fd){
        perror("Opening");
        exit(EXIT_FAILURE);
    }
    char buf[BUFSIZ];
    int n;
    while (n = read(fd, buf, BUFSIZ)){
        if (-1 == n){
            perror("Reading");
            exit(EXIT_FAILURE);
        }
        if (write(STDOUT_FILENO, buf, n) == -1){
            perror("Writing");
            exit(EXIT_FAILURE);
        }
    }
    if (close(fd) == -1){
        perror("Closing");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}