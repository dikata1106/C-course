#include <stdio.h>
#include <stdint.h>

void printNum(const void* nump, int code){
    if (code == 1){
        int* p = (int*)nump;
        printf("Integer Number = %d\n", *p);
    } else if (code == 2){
        double* p = (double*)nump;
        printf("Integer Number = %lf\n", *p);
    }
}

void increment(int* a)
{
    *a++;
}

void swap(int* a, int* b) // formalni parametri
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int main(){
    
    return 0;
}