// Daniel Ruskov Vangelov 30/10/2021
#include <stdarg.h>
#include <stdio.h>
#include <math.h>

int triangleCalc(unsigned a, unsigned b, unsigned c, double* area, double* perimeter) {
    if(a+b<=c || b+c<=a || c+a<=b) {
        *area = *perimeter = 0.0;
        return -1;
    }
    *perimeter = a+b+c;
    double semiperimeter = *perimeter/2;
    *area = sqrt( semiperimeter*(semiperimeter-a)*(semiperimeter-b)*(semiperimeter-c) );
    return 0;
}
/*
unsigned onesCount(unsigned count, size_t size, ...) {
    unsigned ones = 0, i, j, mask;
    va_list args;
    va_start(args, size);
    for (i=0; i<count; i++) {
        mask = va_arg(args, int);
        for(j=0; j<sizeof(int)*8; j++) {
            if ((mask & (1<<j) != 0))
                ones++;
        }
    }
    va_end(args);
    return ones;
}
*/
/*
unsigned onesCount(unsigned count, size_t size, ...) {
    unsigned ones = 0, i, j, mask, totalBits, firstIterations, restIterations;
    totalBits = count * size * 8;
    firstIterations = totalBits / (sizeof(int)*8);
    restIterations = totalBits - firstIterations*sizeof(int)*8;
    printf("count %d, size %ld, firstIterations %d, restIterations %d\n", count, size, firstIterations, restIterations);
    va_list args;
    va_start(args, size);
    for (i=0; i<firstIterations; i++) {
        mask = va_arg(args, int);
        for(j=0; j<sizeof(int)*8; j++) {
            if (mask & (1<<j)) {
                ones++;
                printf("+> ");
            }
            printf("%d %d, ", i, j);
        }
        printf("\n");
    }
    mask = va_arg(args, int);
    for(j=0; j<restIterations; j++) {
        if (mask & (1<<(j-sizeof(int)+restIterations))) {
            ones++;
            printf("+> ");
        }
        printf("%d, ", j);

    }
    printf("\n");
    va_end(args);
    return ones;
}
*/
unsigned onesCount(unsigned count, size_t size, ...) {
    unsigned ones = 0, i, j, mask;
    va_list args;
    va_start(args, size);
    for (i=0; i<count; i++) {
        mask = va_arg(args, int);
        for(j=0; j<sizeof(int)*8; j++) {
            if (mask & (1<<j)) {
                ones++;
                //printf("+> ");
            }
            //printf("%d %d, ", i, j);
        }
        //printf("\n");
    }
    va_end(args);
    return ones;
}
int main(void) {
    double a, p;
    printf("area = %f, perimeter = %f, triangleCalc return code = %d\n", a, p, triangleCalc(3, 6, 5, &a, &p));
    printf("area = %f, perimeter = %f, triangleCalc return code = %d\n", a, p, triangleCalc(3, 3, 3, &a, &p));
    printf("onesCount(6, 1, 0b11110000, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111) = %d ones\n", onesCount(6, 1, 0b11110000, 0b11111111, 0b11111111, 0b11111111, 0b11111111, 0b11111111));
    printf("onesCount(5, 2, 0b0101010100001111, 0b1000000101111110, 0b0001100010000000, 0b0101010100001111, 0b0101010100001111) = %d ones\n", onesCount(5, 2, 0b0101010100001111, 0b1000000101111110, 0b0001100010000000, 0b0101010100001111, 0b0101010100001111));
    return 0;
}