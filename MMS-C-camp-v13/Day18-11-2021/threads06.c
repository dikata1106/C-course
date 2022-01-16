#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 10

sem_t semaphore;

void* routine(void* arg){
    sem_wait(&semaphore);
    sleep(1);
    printf("Hello from thread %d\n", *(int*)arg);
    sleep(1);
    sem_post(&semaphore);
    free(arg);
}

int main(void){
    pthread_t th[THREADS_COUNT];
    sem_init(&semaphore, 0, 4);
    for (int i = 0; i < THREADS_COUNT; i++){
        int *num = malloc(sizeof(int));
        *num = i;
        if (pthread_create(&th[i], NULL, routine, num) != 0){
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
    sem_destroy(&semaphore);
    return 0;
}