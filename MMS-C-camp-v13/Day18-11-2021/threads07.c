#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <semaphore.h>

#define THREADS_COUNT 10

sem_t loginSem;

void* routine(void* arg){
    printf("(%d) is waiting in the login queue\n", *(int*)arg);
    sem_wait(&loginSem);
    printf("Logged in.\n");
    sleep(1 + rand() % 5);
    printf("Logged out.\n");
    sem_post(&loginSem);
    free(arg);
}

int main(void){
    srand(time(NULL));
    pthread_t th[THREADS_COUNT];
    sem_init(&loginSem, 0, 1);
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
    sem_destroy(&loginSem);
    return 0;
}