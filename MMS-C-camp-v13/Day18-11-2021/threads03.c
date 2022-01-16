#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

int arr[11] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };

void* routine(void* arg){
    int index = *(int*)arg;
    printf("%d ", arr[index]);
    free(arg);
}

int main(void){
    pthread_t th[10];
    for (int i = 0; i < 10; i++){
        int* num = malloc(sizeof(int));
        *num = i;
        if (pthread_create(&th[i], NULL, routine, num) != 0){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < 10; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            exit(EXIT_FAILURE);
        }
    } 
    putchar('\n');   
    return 0;
}