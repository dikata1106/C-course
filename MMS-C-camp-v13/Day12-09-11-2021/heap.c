#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 99999999


int main(){
    srand(time(NULL));
    int* arr = malloc(COUNT * sizeof(int));
    if (arr == NULL){
        printf("Can't allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < COUNT; i++){
        i[arr] = rand() % 10;
    }

    int n;
    scanf("%d", &n);
    arr = realloc(arr, (n + COUNT)*sizeof(int));
    if (arr == NULL){
        printf("Can't allocate memory!\n");
        exit(EXIT_FAILURE);
    }
    for (int i = COUNT; i < (n + COUNT); i++){
        arr[i] = 9;
    }
    for (int i = 0; i < COUNT + n; i++){
        printf("%d ", *(arr + i));
    }
    putchar('\n');
    free(arr);
    return EXIT_SUCCESS;
}