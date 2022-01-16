// Daniel Ruskov Vangelov 01/11/2021
#include <stdio.h>
#include <stdarg.h>

#define CHECKBIT(mask, bit) ( ((mask) & (1<<(bit))) ? 1 : 0 )

size_t bitsNCount(size_t count, size_t bitscnt, ...) {
    int i, j, cntTrueMasks = 0, countBits = 0, mask;
    va_list args;
    va_start(args, bitscnt);
    for (i=0; i<count; i++) {   // for every int
        mask = va_arg(args, int);
        for (j=0; j<sizeof(int)*8; j++) { // count it's number of 1's
            // printf("i = %d, j = %d, mask = %d\n", i, j, mask);
            if (mask & (1<<j)) {
                countBits++;
                // printf("countBits++\n");
            }
        }
        if (countBits == bitscnt) {
            cntTrueMasks++;
            // printf("cntTrueMasks++\n");
        }
        countBits = 0;
    }
    va_end(args);
    return (size_t)cntTrueMasks;
}


int main(void) {
    printf("%ld = bitsNCount(4, 2, 0x0a, 0xff, 0, 1)\n", bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%ld = bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa)\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%ld = bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111)\n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111));
    return 0;
}