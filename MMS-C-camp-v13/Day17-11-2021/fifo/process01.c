#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6 };
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    int start, end;

    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0){
        start = 0;
        end = arrSize / 2;
        sleep(5);
    } else {
        start = arrSize / 2;
        end = arrSize;
    }

    int sumP = 0;
    for (int i = start; i < end; i++){
        sumP += arr[i];
    }
    printf("My sum = %d\n", sumP);

    if (pid > 0){
        wait(NULL);
    }
    return 0;
}

