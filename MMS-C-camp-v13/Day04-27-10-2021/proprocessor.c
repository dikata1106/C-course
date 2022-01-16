#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <limits.h>

unsigned onesCount(int cnt, int size, ...){
    unsigned count = 0;
    va_list list;
    va_start(list, size);
    for (int i = 0; i < cnt; i++){
        int m = va_arg(list, int);
        for (int j = 0; j < 16; j++){
            count += (m & (1 << j)) ? 1 : 0;
        }
    }
    va_end(list);
    return count;
}

int main(){
    int a = 10;
    int b = 20;
    printf("%d \n", onesCount(2, sizeof(uint16_t), (uint16_t)0b0100000001000000, (uint16_t)0b0000000000000000));
    return 0;
}