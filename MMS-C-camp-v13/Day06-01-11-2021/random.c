#include <stdio.h>
#include <math.h>
#include "myrandom.h"

double pi(int n){
    int pointsIn = 0;
    for (int i = 0; i < n; i++){
        double x = randomReal();
        double y = randomReal();
        pointsIn += (sqrt(x*x + y*y) < 1);
    }
    return (4.0 * pointsIn) / n;
}

int main(void){
    srand(time(NULL));
    printf("PI = %.5lf\n", pi(10));
    printf("PI = %.5lf\n", pi(100));
    printf("PI = %.5lf\n", pi(1000));
    printf("PI = %.5lf\n", pi(10000));
    printf("PI = %.5lf\n", pi(100000));
    return 0;
}

