#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;
int main(int argc, char* argv[]) {
    if (mkfifo("sum", 0777) == -1) {
        if (errno != EEXIST) {
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }
    int arr[5];
    srand(time(NULL));
    int i;
    for (i = 0; i < 5; i++) {
        arr[i] = rand() % 100;
        printf("Generated %d\n", arr[i]);
    }
    
    // NOTE: You will have to create the fifo using the command "mkfifo sum"
    int fd = open("sum", O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    if (write(fd, arr, sizeof(int) * 5) == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    
    close(fd);
    
    return 0;
}