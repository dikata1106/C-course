#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdarg.h>

#define LOOPI(begin, end, step) for(int i = (begin); i <= (end); i+=(step))
#define LOOPJ(begin, end, step) for(int j = (begin); j <= (end); j+=(step))

#define INT 1
#define FLOAT 8
#define DOUBLE 4
#define UINT8 8
#define UINT16 16
#define UINT32 32
#define UINT64 64
#define CHAR 128

int quadratic(double a, double b, double c, double* x1, double *x2){
    double D = b*b - 4*a*c;
    if (fabs(D) < 1e-5){
        *x1 = *x2 = -b/(2*a);
        return 0;
    }
    if (D < 0){
        *x1 = *x2 = 0;
        return -1;
    }
    *x1 = (-b + sqrt(D)) / (2*a);
    *x2 = (-b - sqrt(D)) / (2*a);
    return 0;
}

void printValue(const void* valuePtr, uint8_t flag){
    if (flag & INT){
        printf("Value: %d\n", *(int*)valuePtr);
    } else if (flag & DOUBLE) {
        printf("Value: %lf\n", *(double*)valuePtr);
    } else if (flag & FLOAT) {
        printf("Value: %f\n", *(float*)valuePtr);
    } else if (flag & CHAR) {
        printf("Value: %c\n", *(char*)valuePtr);
    } else if (flag & UINT8) {
        printf("Value: %d\n", *(uint8_t*)valuePtr);
    } else if (flag & UINT16) {
        printf("Value: %d\n", *(uint16_t*)valuePtr);
    } else if (flag & UINT32) {
        printf("Value: %d\n", *(uint32_t*)valuePtr);
    } else if (flag & UINT64) {
        printf("Value: %ld\n", *(uint64_t*)valuePtr);
    }
}

size_t bitsNCount(size_t count, size_t bitscnt, ...){
    int cnt = 0;
    va_list args;
    va_start(args, bitscnt);
    for (int i = 0; i < count; i++){
        int mask = va_arg(args, int);
        int c = 0;
        for (int bit = 0; bit < CHAR_BIT * sizeof(int); bit++){
            c += !!(mask & (1 << bit));  
        }
        cnt += (bitscnt == c);
    }
    va_end(args);
    return cnt;
}

int main(){
    double a, b, c, x1, x2;
    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if (quadratic(a, b, c, &x1, &x2)){
        printf("No real roots!\n");
    } else {
        printf("x1 = %.3f, x2 = %.3f\n", x1, x2);
    }

    /*double aa = 10.34;
    char cc = 'Z';
    float pi = 3.1415f;
    uint64_t s = 123454345434;
    printValue(&aa, DOUBLE);
    printValue(&cc, CHAR);
    printValue(&pi, FLOAT);
    printValue(&s, UINT64); */

    printf("%ld \n", bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%ld \n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%ld \n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111));

    return 0;
}