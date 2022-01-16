#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

double avgNums(int, ...);
int sumNums(int, ...);
int randInt(int, int);
double randReal(void);
double randRange(double, double);
double calcPI(int);

int main(){
    srand(time(NULL));
    printf("pi = %.2lf\n", calcPI(10000000));
    printf("Sum nums: %d\n", sumNums(5, 1, 2, 3, 4, 50));
    printf("Average nums: %lf\n", avgNums(3, 1.0, 2.0, 3.0));
    return 0;
}

double avgNums(int cnt, ...){
    double sum = 0;
    va_list list;
    va_start(list, cnt);
    for (int i = 0; i < cnt; i++){
        sum += va_arg(list, double);
    }
    va_end(list);
    return sum / cnt;
}

int sumNums(int cnt, ...){
    int sum = 0;
    va_list list;
    va_start(list, cnt);
    for (int i = 0; i < cnt; i++){
        sum += va_arg(list, int);
    }
    va_end(list);
    return sum;
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1);    
}

double randReal(void){
    return (double)rand() / RAND_MAX;
}

double randRange(double min, double max){
    return min + randReal() * (max - min) ;
}

double calcPI(int n){
    int cntIn = 0;
    for (int i = 0; i < n; i++){
        double x = randRange(0.0, 1.0);
        double y = randRange(0.0, 1.0);
        if (sqrt(x*x + y*y) <= 1.0){
            cntIn++;
        }
    }
    return (float)cntIn / n * 4.0;
}
