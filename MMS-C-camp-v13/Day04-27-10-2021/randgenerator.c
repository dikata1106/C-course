#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>
#include "randfun.h"

int main(){
    srand(time(NULL));
    printf("pi = %.2lf\n", calcPI(10000000));
    printf("Sum nums: %d\n", sumNums(5, 1, 2, 3, 4, 50));
    printf("Average nums: %lf\n", avgNums(3, 1.0, 2.0, 3.0));
    return 0;
}