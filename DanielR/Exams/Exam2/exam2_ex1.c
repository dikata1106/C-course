#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define COUNT 10

typedef struct {
    char model[15];
    uint8_t maxspeed;
    double price;
} Car;

int randomInt(int min, int max);
double randomReal(double min, double max);
void generateCars(Car* b, size_t n);
void printCars(Car* arr, size_t n);
int compareModelAZ(const void* a, const void* b);
int compareModelZA(const void* a, const void* b);
int compareSpeedMinMax(const void* a, const void* b);
int compareSpeedMaxMin(const void* a, const void* b);
int comparePrice_0_9(const void* a, const void* b);
int comparePrice_9_0(const void* a, const void* b);
int (*getComparator(int n))(const void*, const void*);

int main(void) {
    Car cars[COUNT];
    int n;
    srand(time(NULL));
    generateCars(cars, COUNT);
    printf("Enter a number function for sorting compare 1..6: ");
    scanf("%d", &n);
    int (*f)(const void*, const void*) = getComparator(n);
    (f != NULL) ? qsort(cars, COUNT, sizeof(*cars), f) : printf("ERROR: NULL POINTER TO F. Cannot sort.\n");
    printCars(cars, COUNT);

    return 0;
}

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void generateCars(Car* b, size_t n) {
    int i, j, chars;
    for (i=0; i<n; i++) {
        b[i].maxspeed = randomInt(100, 300);
        b[i].price = randomReal(1000.00, 100000.00);

        chars = randomInt(4, 10);
        b[i].model[0] = randomInt('A', 'Z');
        for(j=1; j<chars; j++) {
            b[i].model[j] = randomInt('a', 'z');
        }
        b[i].model[j] = '\0';
    }
    return;
}

void printCars(Car* arr, size_t n) {
    int i;
    for (i=0; i<n; i++) {
         printf("Model: %11s,\tMax speed: %hd,\tPrice: %.2lf\n", arr[i].model, arr[i].maxspeed, arr[i].price);
    }
    return;
}

int compareModelAZ(const void* a, const void* b) {
    return strcmp((*((Car*)a)).model, ((Car*)b)->model);
}

int compareModelZA(const void* a, const void* b) {
    return strcmp((*((Car*)b)).model, ((Car*)a)->model);
}

int compareSpeedMinMax(const void* a, const void* b) {
    return (*((Car*)a)).maxspeed - ((Car*)b)->maxspeed;
}

int compareSpeedMaxMin(const void* a, const void* b) {
    return (*((Car*)b)).maxspeed - ((Car*)a)->maxspeed;
}

int comparePrice_0_9(const void* a, const void* b) {
    double p1 = (*((Car*)a)).price, p2 = ((Car*)b)->price;
    if (fabs(p1-p2) < (1e-5*fmax(p1, p2))) { //  a1 == a2
        return 0;
    } else if (p1<p2) {
        return -1;
    } else {
        return 1;
    }
}

int comparePrice_9_0(const void* a, const void* b) {
    double p1 = (*((Car*)b)).price, p2 = ((Car*)b)->price;
    if (fabs(p1-p2) < (1e-5*fmax(p1, p2))) { //  a1 == a2
        return 0;
    } else if (p1<p2) {
        return -1;
    } else {
        return 1;
    }
}

int (*getComparator(int n))(const void*, const void*) {
    switch (n) {
        case 1:
            return compareModelAZ;
            break;
        case 2:
            return compareModelZA;
            break;
        case 3:
            return compareSpeedMinMax;
            break;
        case 4:
            return compareSpeedMaxMin;
            break;
        case 5:
            return comparePrice_0_9;
            break;
        case 6:
            return comparePrice_9_0;
            break;
        default:
            return NULL;
    }
}

