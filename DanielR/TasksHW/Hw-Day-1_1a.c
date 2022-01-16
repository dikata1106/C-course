// Daniel Ruskov Vangelov 25/10/2021

#include <stdio.h>

int main() {
    double m, h, bmi;
    printf("Enter M:");
    scanf("%lf", &m);
    printf("Enter H:");
    scanf("%lf", &h);
    bmi = m / (h*h);
    printf("BMI = %.2lf\n", bmi);
    return 0;
}
