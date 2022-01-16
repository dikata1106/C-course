// Daniel Ruskov Vangelov 01/11/2021
#include <stdio.h>
#include <stdint.h>

#define TINT 1
#define TCHAR 2
#define TDOUBLE 4
#define TFLOAT 8
#define TUINT8 16
#define TUINT16 32
#define TUINT32 64
#define TUINT64 128

void printValue(const void* valuePtr, uint8_t flag) {
    switch (flag) {
        case TINT:
            printf("%d\n",*((int*)valuePtr));
            break;
        case TUINT8:
            printf("%d\n",*((uint8_t*)valuePtr));
            break;
        case TUINT16:
            printf("%d\n",*((uint16_t*)valuePtr));
            break;
        case TUINT32:
            printf("%d\n",*((uint32_t*)valuePtr));
            break;
        case TUINT64:
            printf("%ld\n",*((uint64_t*)valuePtr));
            break;
        case TCHAR:
            printf("%c\n",*((char*)valuePtr));
            break;
        case TDOUBLE:
            printf("%.2f\n",*((double*)valuePtr));
            break;
        case TFLOAT:
            printf("%f\n",*((float*)valuePtr));
            break;
        default:
            break;
    }
}

int main(void) {
    int num1 = 23;
    printValue(&num1, TINT);
    double num2 = 3.14;
    printValue(&num2, TDOUBLE);
    char symbol = 'A';
    printValue(&symbol, TCHAR);
    return 0;
}