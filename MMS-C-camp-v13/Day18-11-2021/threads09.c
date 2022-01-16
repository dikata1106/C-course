#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 1

sem_t binSem;
int* fuel;

pthread_mutex_t mutex;

void* routine(void* arg){
    sleep(1);
    *fuel += 50;
    printf("Fuel value is: %d\n", *fuel);
    sem_post(&binSem);
}

int main(void){
    pthread_t th[THREADS_COUNT];
    sem_init(&binSem, 0, 0);
    pthread_mutex_init(&mutex, NULL);
    fuel = malloc(sizeof(int));
    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_create(&th[i], NULL, routine, NULL) != 0){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }
    
    sem_wait(&binSem);
    free(fuel);
    printf("Deallocating fuel\n");


    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
    sem_destroy(&binSem);
    pthread_mutex_destroy(&mutex);
    return 0;
}