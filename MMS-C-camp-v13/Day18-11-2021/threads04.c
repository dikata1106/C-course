#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 10
#define ITER_COUNT 10000
unsigned long x = 0;

sem_t binSem;
pthread_mutex_t mutex;

void* routine(void* arg){
    for (int i = 0; i < ITER_COUNT; i++){
        //pthread_mutex_lock(&mutex);
        sem_wait(&binSem);
        x++;
        sem_post(&binSem);
       // pthread_mutex_unlock(&mutex);
    }
}

int main(void){
    pthread_t th[THREADS_COUNT];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&binSem, 0, 1);
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
    sem_destroy(&binSem);
    pthread_mutex_destroy(&mutex);
    unsigned long expected = THREADS_COUNT * ITER_COUNT;
    unsigned long diff = expected - x;
    printf("Expected = %lu\n", expected);
    printf("X = %lu\n", x);
    printf("Difference = %lu\n",diff);
    return 0;
}