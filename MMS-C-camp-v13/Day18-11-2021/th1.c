#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 10

pthread_mutex_t mutex;
sem_t semWC;


void* routine(void* args){
    //printf("Waiting....!\n");
    sem_wait(&semWC);
    printf("I'm in WC...\n");
    sleep(10);
    sem_post(&semWC);
    printf("Go away!\n");
}

int main(){
    pthread_t th[THREADS_COUNT];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&semWC, 0, 5);
    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_create(&th[i], NULL, routine, NULL) != 0){
            perror("thread create");
            exit(EXIT_FAILURE);
        }
    }
  
    for (int i = 0; i < THREADS_COUNT; i++){
        if(pthread_join(th[i], NULL) != 0){
            perror("thread join");
            exit(EXIT_FAILURE);
        }   
    }
    pthread_mutex_destroy(&mutex);
    sem_destroy(&semWC);
    return 0;
}