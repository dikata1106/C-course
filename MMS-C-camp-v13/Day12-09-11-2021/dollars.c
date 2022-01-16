#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#define N 20

int main(){
    char **dolars = malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++){
        dolars[i] = calloc((i + 2), sizeof(char));
        memset(dolars[i], '#', i + 1);
    }
    for (int i = 0; i < N; i++){
        printf("%s\n", dolars[i]);
    }

    for (int i = 0; i < N; i++){
        free(dolars[i]);
    }
    free(dolars);
    return EXIT_SUCCESS;
}