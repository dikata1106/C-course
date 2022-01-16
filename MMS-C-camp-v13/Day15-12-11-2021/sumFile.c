#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
    FILE *fp = fopen("copyfile", "r");
    if (fp == NULL){
        printf("Error");
        exit(EXIT_FAILURE);
    }
    int sum = 0;
    int num;

    fseek(fp, 0, SEEK_END);
    int end = ftell(fp);
    int mid = end / 2;
    fseek(fp, mid, SEEK_SET); // mid file

    while ((num = fgetc(fp)) != EOF){
        putchar(num);
    }
    fclose(fp);
    /*fp = fopen("copyfile", "a");
    fprintf(fp, "Sum = %d", sum);
    fclose(fp);*/
    return 0;
}