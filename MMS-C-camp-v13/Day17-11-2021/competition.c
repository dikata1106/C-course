#include <sys/mman.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <fcntl.h>
 #include <sys/mman.h>
#include <sys/stat.h>
const char* semName = "semy"; 
int main(void){
    int* num = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS , -1, 0);
    if (MAP_FAILED == num){
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid == 0){
        sem_t *sem = sem_open(semName, O_CREAT, 0600, 1);
        for (int i = 0; i < 100000; i++){
            sem_wait(sem);
            (*num)++;
            sem_post(sem);
        }
    } else {
        sem_t *sem = sem_open(semName, O_CREAT, 0600, 1);
        for (int i = 0; i < 100000; i++){
            sem_wait(sem);
            (*num)++;
            sem_post(sem);
        }
        wait(NULL);
        printf("Number = %d\n", *num);
    }

    return EXIT_SUCCESS;
}