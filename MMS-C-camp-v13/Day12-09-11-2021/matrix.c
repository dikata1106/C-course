#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 20


int main(){
    int matrix[N][M];

   for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            *(*(matrix+i)+j) = rand() % 10; // matrix[i][j] = 
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", *(*(matrix+i)+j));
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}