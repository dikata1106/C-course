#include <stdio.h>
#include <math.h>

int main(){
    double r, l, v;
    printf("Enter R: ");
    scanf("%lf", &r);
    printf("Enter L: ");
    scanf("%lf", &l);
    v = 2 * M_PI * r * r  * l;
    printf("Volume = %.2lf m^3\n", v);
    return 0;
}