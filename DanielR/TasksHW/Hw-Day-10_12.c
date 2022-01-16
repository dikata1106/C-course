#include <stdio.h>
#include <stdint.h>

#define CHECKBIT(m, b) (!!((m)&(1<<(b))))

typedef union {
    float real;
    uint32_t bits;
} RealNumber;

typedef union {
    uint16_t word;
    struct {
        uint8_t byte0;
        uint8_t byte1;
    };
} word16;

typedef struct {
    uint32_t maskArr[100];
    uint8_t nitems;
} StatiList;

void swapBytes(uint16_t*);
int clearBit(uint32_t*, size_t, size_t);
int setBit(uint32_t*, size_t, size_t);
int checkBit(uint32_t*, size_t, size_t);

int main(void) {
    RealNumber r;
    printf("Enter a real number: ");
    scanf("%f", &r.real);
    printf("Decomposed into bits: ");
    int i;
    for(i=sizeof(r.bits)*8-1; i>=0; i--){
        printf("%d", CHECKBIT(r.bits, i));
    }
    putchar('\n');

    uint16_t w1= 0xaaff;
    printf("\nBefore swap: %x, ", w1);
    swapBytes(&w1);
    printf("after swap: %x\n", w1);

    
    return 0;
}

void swapBytes(uint16_t* word) {
    word16 tmp = {*word};
    tmp.byte0 ^= tmp.byte1;
    tmp.byte1 ^= tmp.byte0;
    tmp.byte0 ^= tmp.byte1;
    *word = tmp.word;
}

int clearBit(uint32_t* maskArr, size_t nitems, size_t bit);
int setBit(uint32_t* maskArr, size_t nitems, size_t bit);
int checkBit(uint32_t* maskArr, size_t len, size_t bit);