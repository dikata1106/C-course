#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]) {
    int fd[2];
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    
    if (pid == 0) {
        srand(time(NULL));
        close(fd[0]);
        int n, i;
        int arr[10];
        n = 1 + rand() % 10;
        printf("Generated: ");
        for (i = 0; i < n; i++) {
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
        }
        printf("\n");
        if (write(fd[1], &n, sizeof(int)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        printf("Sent n = %d\n", n);
        
        if (write(fd[1], &arr, sizeof(int) * n) < 0)  {
            perror("write");
            exit(EXIT_FAILURE);
        }
        
        printf("Sent array\n");
        close(fd[1]);
    } else {
        close(fd[1]);
        int arr[10];
        int n, i, sum = 0;
        
        if (read(fd[0], &n, sizeof(int)) < 0)  {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Received n = %d\n", n);
        if (read(fd[0], &arr, sizeof(int) * n) < 0) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        printf("Received array\n");
        
        close(fd[0]);
        for (i = 0; i < n; i++) {
            sum += arr[i];
        }
        printf("Result is %d\n", sum);
        wait(NULL);
    }
    
    return 0;
}