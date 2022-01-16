#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
extern int errno;

void readBack(int fd){
    char ch;
    int n = -1;
    while (lseek(fd, n, SEEK_END) != -1){
        read(fd, &ch, 1);
        write(STDOUT_FILENO, &ch, 1);
        n--;
    }
    ch = '\n';
    write(STDOUT_FILENO, &ch, 1);
    
}

int main(){
    int fdErrorLog = 1000;// = open("errorlog.txt", O_WRONLY | O_CREAT | O_APPEND);
    if (dup2(fdErrorLog, STDERR_FILENO) == -1){
        perror("Redirecting");
        if (errno == EBADF){
            //....
        }
        exit(EXIT_FAILURE);
    }
    dup2(fdErrorLog, STDOUT_FILENO);
    fprintf(stderr, "Error message!\n");
    printf("Hello\n");
    close(fdErrorLog);
    return 0;
}