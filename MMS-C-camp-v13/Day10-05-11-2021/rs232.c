#include <stdio.h>
#include <stdint.h>
#define SETBIT(mask, bit) ((mask) |= (1 << (bit)))

void printBytes(const char* rs){
    char ch;
    int cnt = 0;
    uint8_t byte = 0;
    char start = 0;
    while ((ch = *rs++) != '\n'){
        if (ch == '0' && start == 0){
            start = 1;
            continue;
        }
        if (start){
            if (ch == '1') {
                SETBIT(byte, cnt);
            }
            cnt++;
        }
        if (cnt == 8){
            printf("%x", byte);
            byte = start = cnt = 0;
        }
    }
}


int main(void){
   printBytes("111111");
    putchar('\n');
    return 0;
}