#include "functions.h"
/* printNumber("dbox", 10, 20, 30, 40) */
// d - DEC, b -> BIN, o -> OCT, x -> HEX
void printArgs(char* fmt, ...){
    va_list args;
    va_start(args, fmt);
    while (*fmt){
        switch(*fmt++){
            case 'd':
                printf("%d\n", va_arg(args, int));
                break;
            case 'f':
                printf("%lf\n", va_arg(args, double));
                break;
            case 'c':
                printf("%c\n", (char)va_arg(args, int));
                break;
            case 's':
                printf("%s\n", va_arg(args, char*));
                break;
        }
    }
    va_end(args);
}


int countEven(int cnt, ...){
    int count = 0;
    va_list args;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++){
        if(!(va_arg(args, int) & 1)){
            count++;
        }
    }
    va_end(args);
    return count;
}

void printInfo(){
    printf("MMS C Camp\n");
}

void printHello(int n){
    if (n == 0) return;
    printf("Hello\n");
    if (n == 1){
        return;
    }
    printf("Hello\n");
}
int sumNums(int cnt, ...){
    int sum = 0;
    va_list args;
    va_start(args, cnt);
    for (int i = 0; i < cnt; i++){
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}


double power2(double x){
    return x * x;
}

double f(double x){
    return 2 * power2(x);
}

int maxInt(int a, int b){
    return (a > b) ? a : b;
}
