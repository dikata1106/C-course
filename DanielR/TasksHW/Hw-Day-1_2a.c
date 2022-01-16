// Daniel Ruskov Vangelov 25/10/2021

#include <stdio.h>
#include <math.h>

int main() {
    double r, l, v;
    printf("Enter R:");
    scanf("%lf", &r);
    printf("Enter L:");
    scanf("%lf", &l);
    v = 2*M_PI*pow(r, 2)*l; // cant use r<<1 in non integer
    printf("Volume = %.2lf m3\n", v);
    return 0;
}
