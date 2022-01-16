#include <stdio.h>
#include "max.h"

#define PI 3.1415
#define SUM(x, y) ((x) + (y))
#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MULT(a, b) ((a) * (b))
#define CHECKBIT(mask, bit) (((mask) & (1 << (bit))) ? 1 : 0)



int main(void){
    /*double r = 10.5;
    double S = PI * r * r;
    double C = 2 * PI * r;
    int a = SUM(10, 2);
    printf("%d ", MAX(a, 29.4));
    int a = MULT(10 + 30, 20);
    printf("a = %d\n", CHECKBIT(0xfa, 0));*/
    int a = 10, b = 0;
    int m = MAX(a, b);
    printf("a = %d\nb = %d\nm = %d\n", a, b, m);
    return 0;
}