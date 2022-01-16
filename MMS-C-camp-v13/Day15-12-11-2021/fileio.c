#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if (argc != 3){
        printf("Arguments problem!\n");
        exit(EXIT_FAILURE);
    }
    FILE* fr = fopen(argv[1], "r");
    if (fr == NULL){
        printf("Can't open %s!\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    FILE* fw = fopen(argv[2], "w");
    if (fw == NULL){
        printf("Can't create %s!\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    int sym;
    while ((sym = fgetc(fr)) != EOF){
        fputc(sym, fw);
    }
    fclose(fr);
    fclose(fw);
    printf("Copy successful!\n");
    return 0;
}