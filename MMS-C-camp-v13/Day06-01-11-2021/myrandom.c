#include "myrandom.h"

int randomInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randomReal(void){
    return (double)rand() / RAND_MAX;
}

double randomRealRange(double min, double max){
    return min + randomReal() * (max - min);
}