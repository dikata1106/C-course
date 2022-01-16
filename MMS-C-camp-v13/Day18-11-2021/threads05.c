#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define THREADS_COUNT 10

pthread_mutex_t mutex;

void* routine(void* arg){
    if (pthread_mutex_trylock(&mutex) == 0){
        sleep(1);
        printf("Got locked\n");
        pthread_mutex_unlock(&mutex);
    } else {
        printf("I did'n get locked!\n");
    }
}

int main(void){
    pthread_t th[THREADS_COUNT];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_create(&th[i], NULL, routine, NULL) != 0){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
    pthread_mutex_destroy(&mutex);
    return 0;
}