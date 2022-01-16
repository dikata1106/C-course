#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void* handler(void* args){
    int x = rand() % 10;
    int* result = malloc(sizeof(int));
    *result = x;
    return result;
}

int main(void){
    srand(time(NULL));
    pthread_t p1;
    if (pthread_create(&p1, NULL, handler, NULL) != 0){
        perror("create");
        exit(EXIT_FAILURE);
    }
    int* result;
    if(pthread_join(p1, (void**)&result) != 0){
        perror("join");
        exit(EXIT_FAILURE);
    }
    printf("Result = %d\n", *result);
    free(result);
    return 0;
}