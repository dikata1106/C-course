// https://www.ibm.com/docs/en/i/7.4?topic=functions-fopen-open-files
// gcc Hw-Day-18_2.c -o Hw-Day-18_2 -lpthread
// USE: ./file.exe file1 [list of files]
// hexdump -C file
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <limits.h>
#include <sys/stat.h>
#include <fcntl.h>

// #define CREATE_BINARY 10
#define MIN -50
#define MAX 1000

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void* routine(void *arg) {
    int i, n, num, *nums;
    FILE *fpr = fopen((char *)arg, "rb+");
    if (fpr == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }
    fseek(fpr, 0, SEEK_END);
    n = ftell(fpr);
    rewind(fpr);
    // printf("Open file %s with size %d bytes (%ld ints)\n", (char *)arg, n, n/(sizeof(int)));
    // n = n/sizeof(int);
    // printf("First read from file:    ");
    // for (i = 0; i < n; i++) {
    //     fread(&num, sizeof(int), 1, fpr);
    //     printf("%d ", num);
    // }
    // rewind(fpr);
    // putchar('\n');
    nums = (int *)malloc(sizeof(int)*n);
    fread(nums, sizeof(int), n, fpr);
    rewind(fpr);
    // printf("Array read before qsort: ");
    // for (i = 0; i < n; i++) printf("%d ", nums[i]); putchar('\n');
    qsort(nums, n, sizeof(int), cmpfunc);
    // printf("Array read after qsort:  ");
    // for (i = 0; i < n; i++) printf("%d ", nums[i]); putchar('\n');
    // printf("pos before write in file: %ld\n", ftell(fpr));
    fwrite(nums, sizeof(int), n, fpr);
    // rewind(fpr);
    // printf("File read after write:   ");
    // for (i = 0; i < n; i++) {
    //     fread(&num, sizeof(int), 1, fpr);
    //     printf("%d ", num);
    // }
    // putchar('\n');
    free(nums);
    fclose(fpr);
    // free(arg);   // Not needed, cause arg comes from main argv
    return NULL;
}

int main(int argc, char **argv) {

    if (argc == 1) {
        fprintf(stderr, "Wrong use\n");
    }

    #ifdef CREATE_BINARY
        int i, j, n, num;
        srand(time(NULL));
        umask(0666);
        for (i = 1; i < argc; i++) {
            FILE *fp = fopen(argv[i], "w+b");
            // FILE *fp = creat(argv[i], 0666);    // open(path, O_WRONLY|O_CREAT|O_TRUNC, mode)
            if (fp == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }
            printf("%s: ", argv[i]);
            n = randomInt(1, CREATE_BINARY);
            for (j = 0; j < n; j++) {
                num = randomInt(MIN, MAX);
                fwrite(&num, sizeof(int), 1, fp);
                printf("%d ", num);
            }
            putchar('\n');
            fclose(fp);
        }
    #else
        int N = argc-1;
        pthread_t th[N];
        for (int i = 0; i < N; i++) {
            if (pthread_create(&th[i], NULL, routine, argv[i+1]) != 0) {
                perror("create");
                exit(EXIT_FAILURE);
            }
        }
        for (int i = 0; i < N; i++) {
            if (pthread_join(th[i], NULL) != 0) {
                perror("join");
                exit(EXIT_FAILURE);
            }
        } 
    #endif

    return EXIT_SUCCESS;
}