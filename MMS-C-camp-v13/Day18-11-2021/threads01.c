#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void* handler(void* args){
    printf("Hello form thread!\n");
    sleep(1);
    printf("End of thread!\n");
}

int main(void){
    pthread_t p1, p2;
    pthread_create(&p1, NULL, handler, NULL);
    pthread_create(&p2, NULL, handler, NULL);
    if(pthread_join(p1, NULL) != 0){
        perror("join");
        exit(EXIT_FAILURE);
    } 
    if(pthread_join(p2, NULL) != 0){
        perror("join");
        exit(EXIT_FAILURE);
    }
    return 0;
}