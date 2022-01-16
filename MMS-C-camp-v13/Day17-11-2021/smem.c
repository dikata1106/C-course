#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MESSAGE "Hello world"
#define MESSAGE_LENGTH sizeof(MESSAGE)

int main(void){
    char *message = mmap(NULL, MESSAGE_LENGTH, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    int* i = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    if (MAP_FAILED == message){
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    if (MAP_FAILED == i){
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    switch (fork()){
    case -1:
        perror("fork");
        exit(EXIT_FAILURE);

    case 0:
        *i = 10;
        strcpy(message, MESSAGE);
        exit(EXIT_SUCCESS);

    default:
        if (-1 == wait(NULL)){
            perror("wait");
            exit(EXIT_FAILURE);
        }
        printf("Number %d\n", *i);
        printf("String %s\n", message);
    }

    return EXIT_SUCCESS;
}