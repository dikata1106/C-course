#include "myrandom.h" //include in .c's

void inicRandom(void) {
    srand(time(NULL));
}

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

double randomReal(void) {
    return (double) rand() / RAND_MAX;
}

double randomRealRange(double min, double max) {
    return min + randomReal() * (max-min);
}