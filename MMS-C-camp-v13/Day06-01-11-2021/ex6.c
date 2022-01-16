#include <stdio.h>
#include <math.h>

int quadratEq(double, double, double, double*, double*);

int main(void){
    double a, b, c, x1, x2;
    printf("a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if(quadratEq(a, b, c, &x1, &x2)){
        printf("No real roots!\n");
    } else {
        printf("x1 = %.3lf, x2 = %.3lf\n", x1, x2);
    }
    return 0;
}

int quadratEq(double a, double b, double c, double* x1, double* x2){
    double D = b * b - 4 * a * c;
    if (fabs(D) < 1e-5){ // D == 0  // NEVERRRRR!!! 0.0 == D
        *x1 = *x2 = -b / (2*a);
        return 0;
    }
    if (D < 0){
        *x1 = *x2 = 0;
        return 1; // no real roots
    }
    *x1 = (-b + sqrt(D))/ (2*a);
    *x2 = (-b - sqrt(D))/ (2*a);
    return 0;
}