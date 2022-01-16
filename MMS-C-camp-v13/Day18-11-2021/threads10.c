#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

pthread_barrier_t barrier;

#define THREADS_COUNT 10

void* routine(void* arg){
    printf("We are waiting on barrier!\n");
    pthread_barrier_wait(&barrier);
    printf("We are going on...\n");
}

int main(void){
    pthread_t th[THREADS_COUNT];
    pthread_barrier_init(&barrier, NULL, 3);

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
    pthread_barrier_destroy(&barrier);
    return 0;
}

