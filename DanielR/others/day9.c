#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define COUNT 10

typedef struct {
    double x, y;
} point;

typedef struct {
    point a, b;
} rect;

typedef struct {
    int (*operationInt)(int, int);
    double (*operationReal)(double, double);
} calculation;

int sum(int a, int b) {
    return a+b;
}

int sub(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int mod(int a, int b) {
    return a%b;
}

double mult(double a, double b) {
    return a*b;
}

double sumArr(double* arr, size_t n) {
    int i;
    double sum = 0.0;
    for (i=0; i<n; i++)
        sum += arr[i];
}

double maxArr(double* arr, size_t n) {
    int i;
    double max = *arr;
    for (i=1; i<n; i++)
        if (arr[i] > max)
            max = arr[i];
    return(max);	// assert arr != NULL and arr = int*
}

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printRectangles(rect* arr, size_t n) {
    int i;
    double area;
    for (i=0; i<n; i++) {
        area = fabs(arr[i].a.x - arr[i].b.x) * fabs(arr[i].a.y - arr[i].b.y);
        printf("A(%.1lf, %.1lf); B(%.1lf, %.1lf) --> AREA = %.4lf\n", arr[i].a.x, arr[i].a.y, arr[i].b.x, arr[i].b.y, area);
    }
    return;
}

void inicRectangles(rect* arr, size_t n) {
    int i;
    for (i=0; i<COUNT; i++) {
        arr[i].a.x = randomReal(0.0, 100.0);
        arr[i].a.y = randomReal(0.0, 100.0); 
        arr[i].b.x = randomReal(0.0, 100.0);
        arr[i].b.y = randomReal(0.0, 100.0);
    }
    return;
}

double area(rect r) {
    return fabs(r.a.x - r.b.x) * fabs(r.a.y * r.b.y);
}

int compareArea(const void* a, const void* b) {
    double a1 = area(*(rect*)a);
    double a2 = area(*(rect*)b);
    if (fabs(a1-a2)<(1e-5*fmax(a1, a2))) { //  a1 == a2
        return 0;
    } else if (a1<a2) {
        return 1;
    } else {
        return -1;
    }
}

int areaCompare(const void* a, const void* b) {
    double area1 = fabs(((rect*)a)->a.x - ((rect*)a)->b.x) * fabs(((rect*)a)->a.y - ((rect*)a)->b.y);
    double area2 = fabs(((rect*)b)->a.x - ((rect*)b)->b.x) * fabs(((rect*)b)->a.y - ((rect*)b)->b.y);
    double r = area1-area2;
    if (r == 0.0)
        return 0;
    else if (r<0)
        return -1;
    else
        return 1;
}


int (*func[4])(int, int) = {sum, sub, mul, mod};

double (*dArr[2])(double*, size_t) = {sumArr, maxArr};

int (*getOperation(int num))(int, int) {
    if (num<0 || num>3)
        return NULL;
    return func[num];
}

double (*getArrayOperation(int n))(double*, size_t) {
    return dArr[n];
}

// void (*f) (int, double, int*);
// void (*nameofFunct(param1, param2, param3))(int, double, int*) { }

double g(int x) {
    return 4*x - 3;
}
double f(int (*g)(double), int x) {
    return 3*g(x)*g(x);
}

int main(void) {
    // rect rectangles[COUNT];
    // int i;
    // srand(time(NULL));
    // inicRectangles(rectangles, COUNT);
    // // qsort(rectangles, COUNT, sizeof(rectangles), compareArea);
    // printRectangles(rectangles, COUNT);

    calculation mycalc;
    // mycalc.operationInt = sum; // now sums
    // mycalc.operationInt = sub; // now rests
    // mycalc.operationReal = mult;
    // int res = mycalc.operationInt(10, 20);


    mycalc.operationInt = getOperation(0); //get sum func
    int res = getOperation(2)(2, 5); // mult 2*5

    double d = f(g, 10);
    return 0;
}