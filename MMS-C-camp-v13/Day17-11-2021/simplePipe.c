#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int fd[2];
    pipe(fd); // fd[0] -> reading, fd[1] -> writing
    pid_t pid = fork();

    if(pid == -1){
        perror("fork");
        exit(EXIT_SUCCESS);
    }
    if (pid == 0){
        close(fd[0]);
        int x;
        printf("Enter number: ");
        scanf("%d", &x);
        if (-1 ==write(fd[1], &x, sizeof(int))){
            perror("write pipe");
            exit(EXIT_FAILURE);
        }
        close(fd[1]);
    } else {
        close(fd[1]);
        int num;
        if(-1 == read(fd[0], &num, sizeof(int))){
            perror("read pipe");
            exit(EXIT_SUCCESS);
        }
        close(fd[0]);
        printf("Number from child: %d\n", num);
    }

    return 0;
}