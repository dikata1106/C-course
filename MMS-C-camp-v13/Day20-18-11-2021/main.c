#include <stdio.h>
#include <math.h>

extern int num;
int sum(int,int);
int sub(int,int);
int mult(int,int);
int div(int,int);

int main(void){
    int a = 10;
    int result1 = sum(a, num);
    int result2 = mult(a, num);
    int result3 = sub(a, num);
    int result4 = div(a, num);
    printf("Result1 = %d\n", result1);
    printf("Result2 = %d\n", result2);
    printf("Result3 = %d\n", result3);
    printf("Result4 = %d\n", result4);
    printf("Max(r3, r4) = %d\n", (int)fmax(result3, result4));
    return 0;
}