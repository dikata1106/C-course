#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define N 3
#define M 3

int** scalarMult(int** A, size_t n, size_t m, int num){
    int** R = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        R[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            R[i][j] = num * A[i][j]; 
        }
    }
    return R;
}

int** addMatrix(int** A, int** B, size_t n, size_t m){
    int** R = malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++){
        R[i] = malloc(m * sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            R[i][j] = A[i][j] + B[i][j]; 
        }
    }
    return R;
}

void printMatrix(int** A, size_t n, size_t m) {
    int i, j;
    for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
            printf("%2d ", A[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

int** mulMatrix(int**A, int** B, size_t na, size_t ma, size_t nb, size_t mb) {
    // A[m][n] * B[n][p] = R[m][p]
    int i, j, a;
    if (ma != nb) {
        return NULL;
    }
    int** matrix = malloc(na * sizeof(int*));
    for (i = 0; i < N; i++){
        *(matrix + i) = malloc(mb * sizeof(int));
    }
    for (a = 0; a < na; a++) {
        for (i = 0; i <nb; i++) {
            matrix[i][a] = 0;
            for (j = 0; j < mb; j++) {
                matrix[i][a] += A[i][j] * B[j][a];
            }
        }
    }
}

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

    int** matrix2 = malloc(N * sizeof(int*));

    for (i = 0; i < N; i++){
        *(matrix2 + i) = malloc(M * sizeof(int));
    }

    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            *(*(matrix2+i)+j) = rand() % 10;
        }
    }

    int** matrix3 = mulMatrix(matrix, matrix2, N, M, N, M);

    printMatrix(matrix, N, M);
    printMatrix(matrix2, N, M);
    printMatrix(matrix3, N, M);

    for (int i = 0; i < N; i++){
        free(matrix[i]);
        free(matrix2[i]);
        free(matrix3[i]);
    }
    free(matrix);
    free(matrix2);
    free(matrix3);

    
    return EXIT_SUCCESS;
}