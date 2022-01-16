#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 10

pthread_mutex_t mutexBuffer;

sem_t semFree;
sem_t semIn;

int buffer[10];
int count = 0;

void* producer(void *arg){
    while (1){
        // produce
        int x = rand() % 100;
        sleep(1);
        // add to buffer
        sem_wait(&semFree);
        pthread_mutex_lock(&mutexBuffer);
        buffer[count++] = x;
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semIn);
    }
}

void* consumer(void *arg){
    while (1){
        // consume
        sem_wait(&semIn);
        pthread_mutex_lock(&mutexBuffer);
        int  y = buffer[--count];
        pthread_mutex_unlock(&mutexBuffer);
        sem_post(&semFree);
        printf("Got %d\n", y);
    }
}

int main(void){
    srand(time(NULL));
    pthread_t th[THREADS_COUNT];
    sem_init(&semFree, 0, 10);
    sem_init(&semIn, 0, 0);
    pthread_mutex_init(&mutexBuffer, NULL);
    for (int i = 0; i < THREADS_COUNT; i++){
        if (i % 2 == 0){
            if (pthread_create(&th[i], NULL, producer, NULL) != 0){
                perror("create");

            }
        } else {
            if (pthread_create(&th[i], NULL, consumer, NULL) != 0){
                perror("create");

            }
        }
    }
    for (int i = 0; i < THREADS_COUNT; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
        }
    }
    pthread_mutex_destroy(&mutexBuffer);
    sem_destroy(&semFree);
    sem_destroy(&semIn);
    return 0;
}