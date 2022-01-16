#include <stdio.h>
#include <stdint.h>

uint8_t setBit(uint8_t mask, unsigned bit){
    return mask | (1 << bit);
}


uint8_t clearBit(uint8_t mask, unsigned bit){
    return mask & ~(1 << bit);
}

int checkBit(uint8_t mask, unsigned bit){
    return (mask & (1 << bit)) ? 1 : 0;
}


uint8_t invertBit(uint8_t mask, unsigned bit){
    return mask ^ (1 << bit);
}

void printBits(uint8_t mask){
    for (int i = 128; i >= 1; i /= 2){
        printf("%3d ", i);
    }
    putchar('\n');
    for (int i = sizeof(uint8_t)*8 - 1; i >= 0; i--){
        printf("%3d ", checkBit(mask, i));
    }
    putchar('\n');
    putchar('\n');
}

int main(){
    uint8_t myMask = 0x00ll;
    printf("Initial bit mask:\n");
    printBits(myMask);
    myMask = setBit(myMask, 0);
    myMask = setBit(myMask, 2);
    myMask = setBit(myMask, 4);
    myMask = setBit(myMask, 5);
    myMask = setBit(myMask, 6);
    myMask = setBit(myMask, 7);
    myMask = setBit(myMask, 10); // do nothing 
    printf("Bits after set bits: 0, 2, 4, 6, 7:\n");
    printBits(myMask);

    myMask = clearBit(myMask, 0);
    myMask = clearBit(myMask, 1);  // do noting
    myMask = clearBit(myMask, 7);
    printf("Bits after clearing bits: 0, 7:\n");
    printBits(myMask);

    myMask = invertBit(myMask, 0);
    myMask = invertBit(myMask, 7);
    printf("Bits after inverting bits: 0, 7:\n");
    printBits(myMask);

    printf("Check bit-5: %d\n", checkBit(myMask, 5));
    printf("Check bit-1: %d\n", checkBit(myMask, 1));
    return 0;
}