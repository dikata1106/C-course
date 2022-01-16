#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

#define RW 1

int main(int argc, char **argv){
    
    uint16_t number;

    if (argc != 4){
        printf("Arguments problem!\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[3], "-BT") == 0) {
        FILE* fr = fopen(argv[1], "rb");
        if (fr == NULL){
            printf("Can't open %s!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        FILE* fw = fopen(argv[2], "w");
        if (fw == NULL){
            printf("Can't open or create %s!\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        while (fread(&number, sizeof(uint16_t), 1, fr) > 0) {
            fprintf(fw, "%d\n", number);
        }
        fclose(fr);
        fclose(fw);
        printf("Copy successful!\n");
    } else if (strcmp(argv[3], "-TB") == 0) {
        FILE* fr = fopen(argv[1], "r");
        if (fr == NULL){
            printf("Can't open %s!\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        FILE* fw = fopen(argv[2], "wb");
        if (fw == NULL){
            printf("Can't open or create %s!\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        while(fscanf(fr, "%hd", &number) != EOF) {
            fwrite(&number, sizeof(uint16_t), 1, fw);
        }
        fclose(fr);
        fclose(fw);
        printf("Copy successful!\n");
    } else {
        printf("Invalid argument %s\n", argv[3]);
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}