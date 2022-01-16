#include <stdio.h>
#include <stdint.h>

#define UINT8 0b00000001
#define UINT16 0b00000010
#define UINT32 0b00000100
#define UINT64 0b00001000
#define FLOAT 0b00010000
#define DOUBLE 0b00100000
#define CHAR 0b01000000
#define INT 0b10000000

void printValue(const void* val, const uint8_t flag){
    if (flag & INT){
        int num = *(int*)val;
        printf("Value: %d\n", num);
    } else if (flag & CHAR) {
        char ch = *(char*)val;
        printf("Value: %c\n", ch);
    } else if (flag & UINT8) {
        uint8_t num = *(uint8_t*)val;
        printf("Value: %d\n", num);
    } else if (flag & UINT8) {
        uint16_t num = *(uint16_t*)val;
        printf("Value: %d\n", num);
    } else if (flag & UINT8) {
        uint32_t num = *(uint32_t*)val;
        printf("Value: %d\n", num);
    } else if (flag & UINT8) {
        uint64_t num = *(uint64_t*)val;
        printf("Value: %ld\n", num);
    } else if (flag & FLOAT) {
        float num = *(float*)val;
        printf("Value: %f\n", num);
    } else if (flag & DOUBLE) {
        double num = *(double*)val;
        printf("Value: %lf\n", num);
    } 
}

int main(void)
{
    float a = 10.345f;
    printInfo(&a, FLOAT);
    return 0;
}