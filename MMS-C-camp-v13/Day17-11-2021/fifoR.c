#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    int arr[5];
    int fdFifo = open("mkfifo", O_RDONLY);
    read(fdFifo, arr, sizeof(arr));
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    close(fdFifo);
    return 0;
}