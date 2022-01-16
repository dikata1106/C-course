#include<stdio.h>

#define PI 3.14159
#define TAYLOR_TERMS 10

// Babylonian method for finding square roots
int mySqrt(double n, double *sqrt) {
    double temp = 0;
    if (n < 0.0) {
        return -1;
    }
    *sqrt = n / 2;
    while (*sqrt != temp) {
        temp = *sqrt;
        *sqrt = (n / temp + temp) / 2;
    }
    return 0;
}

double myPow(double n, int pow) {
    int i = 0;
    double res = 1.0;
    while (i < pow) {
        res *= n;
        i++;
    }
    return res;
}

int myFact(int n) {
    return n <= 0 ? 1 : n * myFact(n-1);
}

// Taylor's series for sin(x)
float mySin(int deg) {
    deg %= 360; // make it less than 360
    float rad = deg * PI / 180, sin = 0;
    int i;
    for(i = 0; i < TAYLOR_TERMS; i++) { // That's Taylor series!!
        sin += myPow(-1, i) * myPow(rad, 2 * i + 1) / myFact(2 * i + 1);
    }
    return sin;
}

int main(void) {
    double n, sqrt = 0.0;
    scanf("%lf", &n);
    mySqrt(n, &sqrt) == 0 ? printf("mySqrt(%.4lf) = %.4lf\n", n, sqrt) : printf("The given number is negative!\n");
    // printf("%d, %d, %d\n", myPow(2, 4), myPow(0, 3), myPow(3, 0));
    printf("sin(%.4lf) = %.4lf\n", n, mySin((int)n));

}

