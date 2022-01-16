#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 20

int main(){
    int i, j;
    int** matrix = malloc(N * sizeof(int*));

    for (i = 0; i < N; i++){
        *(matrix + i) = malloc(M * sizeof(int));
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            *(*(matrix+i)+j) = rand() % 10; // matrix[i][j] = 
        }
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        putchar('\n');
    }

    for (i = 0; i < N; i++){
        free(*(matrix + i));
    }
    free(matrix);
    return EXIT_SUCCESS;
}