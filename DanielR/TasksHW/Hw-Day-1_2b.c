// Daniel Ruskov Vangelov 25/10/2021
// https://www.mathsisfun.com/geometry/cylinder-horizontal-volume.html

#include <stdio.h>
#include <math.h>

int main() {

    double r, l, h, a, v;
    printf("Enter R:");
    scanf("%lf", &r);
    printf("Enter L:");
    scanf("%lf", &l);
    printf("Enter H:");
    scanf("%lf", &h);

    a = acos((r-h)/r)*pow(r, 2)-(r-h)*sqrt(2*r*h-pow(h, 2));    // acos(x) = cos-1(x)
    v = a*l;
    printf("Area = %lf u2, Volume = %.2lf u3\n", a, v);

    return 0;
}