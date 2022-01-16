#include <stdio.h>
#include <limits.h>

int checkBit(char, unsigned);

int main(void){
    char a = 86;   // put decimal number here
    for(int i = sizeof(a) * CHAR_BIT - 1; i >= 0; i--){
        putchar(checkBit(a, i) + '0');
    }
    putchar('\n');
    return 0;
}

int checkBit(char mask, unsigned bit){
    return mask & (1 << bit) ? 1 : 0;
}
