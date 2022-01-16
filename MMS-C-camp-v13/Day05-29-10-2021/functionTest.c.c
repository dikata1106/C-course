#include <stdio.h>

double f(double x){
    return 2 * power2(x);
}

double power2(double x){
    return x * x;
}

int main(){
    printf("%.2lf %.2lf %.2lf\n", f(0), f(2), f(10));
    return 0;
}