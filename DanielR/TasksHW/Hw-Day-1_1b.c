// Daniel Ruskov Vangelov 25/10/2021

#include <stdio.h>
#include <math.h>

int main() {
    double m, h, bmi;
    printf("Enter M:");
    scanf("%lf", &m);
    printf("Enter H:");
    scanf("%lf", &h);
    bmi = 1.3*m / pow(h, 2.5);
    printf("BMI = %.2lf\n", bmi);
    return 0;
}
