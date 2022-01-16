#include <stdio.h>
#include <stdint.h>

int f(int a, int b, int c){
    return (!a && b && !c) || (!a && b && c) || (a && b && !c);
}

int xor(int a, int b){
    return (!a && b) || (a && !b); // (a||b)&&!(a&&b)
}

int checkBit(uint16_t mask, int bit){
    return (mask & (1 << bit)) ? 1 : 0;
}

uint16_t setBit(uint16_t mask, int bit){
    return mask | (1 << bit);
}

uint16_t clearBit(uint16_t mask, int bit){
    return mask & ~(1 << bit);
}

void printBits(uint16_t mask){
    for (int i = 16 - 1; i >= 0; i--){
        printf("%d", checkBit(mask, i));
    }
    printf("\n");
}

int main(){
    uint16_t a = 0xffff;
    /*a = setBit(a, 0);
    a = setBit(a, 10);
    a = setBit(a, 2);*/
    a = clearBit(a, 4);
    a = clearBit(a, 5);
    a = clearBit(a, 15);
    printBits(a);
    return 0;
}