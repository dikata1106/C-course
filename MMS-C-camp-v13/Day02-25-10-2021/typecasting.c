#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int main(){
    // explicit casting
    uint64_t num1 = UINT64_MAX;
    uint32_t num2 = num1;
    uint16_t num3 = num1;
    uint8_t num4 = num1;
    int64_t num5 = num1;

    printf("uint64 = %lu\n", num1);
    printf("uint32 = %u\n", num2);
    printf("uint16 = %d\n", num3);
    printf("uint8 = %d\n", num4);
    printf("(signed) int64 = %ld\n", num5);
    return 0;
}