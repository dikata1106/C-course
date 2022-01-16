#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

int main(){
    if(mkfifo("myfifo", 0777) == -1){
        if (errno != EEXIST){
            perror("mkfifo");
            exit(EXIT_FAILURE);
        }
    }

    int arr[] = {1, 2, 3, 4, 5};
    int fdFifo = open("mkfifo", O_WRONLY);
    write(fdFifo, arr, sizeof(arr));
    printf("Array sended!\n");
    close(fdFifo);
    return 0;
}