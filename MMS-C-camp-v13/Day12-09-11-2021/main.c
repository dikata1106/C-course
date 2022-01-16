#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N1 2
#define M1 3

#define N2 3
#define M2 2

int* printMatrix(int** a, int n, int m){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            printf("%2d ", a[i][j]);
        }
        putchar('\n');
    }
}


int** addMatrix(int** A, int** B, int n, int m){
    int** C = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        C[i] = malloc(m*sizeof(int));
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            C[i][j] = A[i][j] + B[i][j]; 
        }
    }
    return C;
}

int** multMatrix(int** A, int** B, int na, int ma, int nb, int mb){
    if (ma != nb){
        return NULL;
    }
    int** C = malloc(sizeof(int*)*na);
    for (int i = 0; i < na; i++){
        C[i] = calloc(mb, sizeof(int));
    }
    for (int i = 0; i < na; i++){
        for (int j = 0; j < mb; j++){
            for (int k = 0; k < ma; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    return C;
}


int main(void){
    srand(time(NULL));
    int** A = malloc(N1*sizeof(int*));
    for (int i = 0; i < N1; i++){
        A[i] = malloc(M1*sizeof(int));
    }

    int** B = malloc(N2*sizeof(int*));
    for (int i = 0; i < N2; i++){
        B[i] = malloc(M2*sizeof(int));
    }
    
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;

    B[0][0] = 7;
    B[0][1] = 8;
    B[1][0] = 9;
    B[1][1] = 10;
    B[2][0] = 11;
    B[2][1] = 12;

    /*for (int i = 0; i < N1; i++){
        for (int j = 0; j < M1; j++){
            A[i][j] = rand() % 2;
        }
    }
    for (int i = 0; i < N2; i++){
        for (int j = 0; j < M2; j++){
            B[i][j] = rand() % 2;
        }
    }*/

    printMatrix(A, N1, M1);
    putchar('\n');
    printMatrix(B, N2, M2);
    putchar('\n');
    
   // int** C = NULL;
    int** C = multMatrix(A, B, N1, M1, N2, M2);
    if (C != NULL){
    printf("Matrix C:\n");
    printMatrix(C, N1, M2);
    for (int i = 0; i < N1; i++){
        free(C[i]);
    }
    free(C);
    }

    for (int i = 0; i < N1; i++){
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < N2; i++){
        free(B[i]);
    }
    free(B);
    
    return 0;
}