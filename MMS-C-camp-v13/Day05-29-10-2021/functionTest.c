#include <stdio.h>
#include <stdarg.h>
#include "functions.h"


void printBin(int num){
    char buff[200];
    int n = 0;
    while (num){
        buff[n++] = num % 2;
        num /= 2;
    }
    for (int i = n - 1; i >= 0; i--){
        putchar(buff[i] + '0');
    }
    putchar('\n');
}

int main(void){
    printBinary(8);
    putchar('\n');
    /*printArgs("bdoxdo", 10, "abcd", 3.14, -4, "Hello", 'R');
    int sym = 'A';
    printf("%c \n", sym);
    printf("%d \n", sumNums(5, 1, 10, 1, 2, 3, 3, 4));
    printf("%d \n", countEven(4, 1, 4, 6, 8));
    printf("f(10) = %lf\n", power2(10));
    printf("f(10) = %lf\n", power2(10));*/
    return 0;
}
