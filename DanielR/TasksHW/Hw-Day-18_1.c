#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>


int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

void* routine(void *arg){
    char str[] = {randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), 
                  randomInt('a', 'z'), '\0'};
    printf("%s\n", str);
}

int main(int argc, char **argv){
    srand(time(NULL));
    if (argc < 2) {
        fprintf(stderr, "Use: %s N\n", argv[0]);
    }

    int N = atoi(argv[1]);
    pthread_t th[N];
    for (int i = 0; i < N; i++){
        if (pthread_create(&th[i], NULL, routine, NULL) != 0){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }
    for (int i = 0; i < N; i++){
        if (pthread_join(th[i], NULL) != 0){
            perror("join");
            exit(EXIT_FAILURE);
        }
    } 
    return 0;
}