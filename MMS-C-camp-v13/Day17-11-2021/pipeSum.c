#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void){
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    int start, end;
    int fd[2];
    pipe(fd);
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (0 == pid){
        start = 0;
        end = arrSize / 2;
    } else {
        start = arrSize / 2;
        end = arrSize;
    }
    int sumP = 0;
    for (int i = start; i < end; i++){
        sumP +=arr[i];
    }
    printf("Partial sum: %d\n", sumP);
    if (pid == 0){
        close(fd[0]);
        write(fd[1], &sumP, sizeof(int));
        close(fd[1]);
    } else {
        close(fd[1]);
        int childSum;
        read(fd[0], &childSum, sizeof(int));
        close(fd[0]);
        printf("Sum = %d\n", sumP + childSum);
    }
    return 0;
}