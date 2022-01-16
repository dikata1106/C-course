// Daniel Ruskov Vangelov 30/10/2021
#include <stdio.h>
#define MAX(x, y, z) ( (((x)>(y)) && ((x)>(z))) ? (x) : ((y)>(z)) ? (y) : (z) )
#define MIN(x, y, z) ( (((x)<(y)) && ((x)<(z))) ? (x) : ((y)<(z)) ? (y) : (z) )
#define SETBIT(mask, bit) ( (mask) |= (1<<(bit)) )
#define CLEARBIT(mask, bit) ( (mask) &= ~(1<<(bit)) )
#define INVERSEBIT(mask, bit) ( (mask) ^= (1<<(bit)) )
#define CHECKBIT(mask, bit) ( ((mask) & (1<<(bit))) ? 1 : 0 )
#define SWAP(a, b) { ((a) ^= (b)); ((b) ^= (a)); ((a) ^= (b)); }

int main(void) {
    int mask = 0, a = 1, b = 9;
    printf("%d\n", MAX(6, 5, 7));
    printf("%d\n", MIN(4, 1, 6));
    SETBIT(mask, 1);
    printf("%d\n", mask);
    CLEARBIT(mask, 1);
    printf("%d\n", mask);
    INVERSEBIT(mask, 1);
    printf("%d\n", mask);
    printf("%d\n", CHECKBIT(mask, 1));
    SWAP(a, b);
    printf("%d %d\n", a, b);
    return 0;
}