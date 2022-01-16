#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <limits.h>

#define TINT 1 // (1 << 0)
#define TFLOAT 2 // (1 << 1)
#define TDOUBLE 4 // (1 << 2)
#define TCHAR 8
#define TUINT8 16
#define TUINT16 32
#define TUINT32 64
#define TUINT64 128

void printValue(const void*, uint8_t);
size_t bitsNCount(size_t, size_t, ...);

int main(void){
    /*int num = 10;
    printValue(&num, TINT);
    double pi = 3.1415;
    printValue(&pi, TDOUBLE);
    char ch = 'M';
    printValue(&ch, TCHAR);*/
    printf("%ld\n", bitsNCount(4, 2, 0x0a, 0xff, 0, 1));
    printf("%ld\n", bitsNCount(3, 8, 0xff, 0x13f1, 0xaaaa));
    printf("%ld\n", bitsNCount(5, 10, 0x0a, 0xa0ff, 0, 10, 0b1010111110111));
  
    return 0;
}

void printValue(const void* valuePtr, uint8_t flag){
    if ((flag & TINT)){
        printf("Value: %d\n", *((int*)valuePtr));
        return;
    }
    if ((flag & TCHAR)){
        printf("Value: %c\n", *((char*)valuePtr));
        return;
    }
    if ((flag & TUINT8)){
        printf("Value: %d\n", *((uint8_t*)valuePtr));
        return;
    }
    if ((flag & TUINT16)){
        printf("Value: %d\n", *((uint16_t*)valuePtr));
        return;
    }
    if ((flag & TUINT32)){
        printf("Value: %d\n", *((uint32_t*)valuePtr));
        return;
    }
    if ((flag & TUINT64)){
        printf("Value: %ld\n", *((uint64_t*)valuePtr));
        return;
    }
    if ((flag & TFLOAT)){
        printf("Value: %f\n", *((float*)valuePtr));
        return;
    }
    if ((flag & TDOUBLE)){
        printf("Value: %lf\n", *((double*)valuePtr));
        return;
    }
}


size_t bitsNCount(size_t count, size_t bitscnt, ...){
    size_t cnt1s = 0;
    va_list args;
    va_start(args, bitscnt);
    for (int i = 0; i < count; i++){
        int mask = va_arg(args, int);
        int n = 0;
        for (int bit = 0; bit < sizeof(int) * CHAR_BIT; bit++){
            n += !!(mask & (1 << bit));
        }
        cnt1s +=  (n == bitscnt);
    }
    va_end(args);
    return cnt1s;
}