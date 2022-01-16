#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define COUNT 100

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point a;
    point b;
} rect;



void addValue(point* p){
    p->x = 10;  //(*p).x = 10;
    p->y = 20; //(*p).y = 20;
}

double area(rect r1){
    return fabs(r1.a.x - r1.b.x) * fabs(r1.a.y - r1.b.y); 
}

int compareArea(const void* a, const void* b){
    double area1 = area(*(rect*)a);
    double area2 = area(*(rect*)b);
    if (fabs(area1 - area2) < (1e-5 * fmax(area1, area2))){  // area1 == area2
        return 0;
    } else if (area1 < area2){
        return 1;
    }
    return -1;
}


typedef struct  {
    int (*operationInt)(int, int);
    double (*operationReal)(double, double);
} calculation;

int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mult(int a, int b){
    return a * b;
}

int mod(int a, int b){

    char* str1, str2;
    char *s1, s2; 
    return a % b;
}

double multD(double a, double b){
    return a * b;
}

double sumArr(double* arr, size_t n){
    double sum = 0.0;
    for (int i = 0; i < n; i++){
        sum += arr[i];
    }
    return sum;
}

double maxArr(double * arr, size_t n){
    double max = arr[0];
    for (int i = 1; i < n; i++){
        max = max < arr[i] ? arr[i] : max;
    }
    return max;
}

int (*func[4])(int,int) = {sum, sub, mult, mod };  

double (*dArr[2])(double*, size_t) = {sumArr, maxArr};

double (*getArrayOperation(int n))(double*, size_t){
    return dArr[n];
}

int (*getOperation(int num))(int, int){
    if (num < 0 || num > 3){
        return NULL;
    }
    return func[num];
}


double g(int x){
    return 4*x - 3;
}

double f(double (*g)(double), int x){
    return 3*g(x)*g(x) + 2*g(x) - 1;
}


int factorial(int n){
    if (n == 0){
        return 1;
    }
    return factorial(n - 1) * n;
}

int sumArrR(int* arr, size_t n) {
    if (!n){
        return 0;
    }
    return arr[0] + sumArrR(arr + 1, n - 1);
}

int productArrR1(int* arr, size_t n,  int start) {
    if (start == n){
        return 1;
    }
    return arr[start] * productArrR1(arr, n, start + 1);
}

int productArrR(int* arr, size_t n) {
    return productArrR1(arr, n, 0);
}

int strsize(const char* str){
    int size = 0;
    while (*(str++)){
        size++;
    }
    return size;
}

int strsizeR(const char* str){
    if (*str == '\0'){
        return 0;
    }
    return 1 + strsizeR(str + 1);
}

int searchChar(const char *str, char key){
    if (*str == '\0'){
        return 0;
    }
    return (*str == key) || searchChar(str + 1, key);
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1); 
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printRectagles(rect* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("A(%.1lf,%.1lf), B(%.1lf,%.1lf)\n", arr[i].a.x, arr[i].a.y, arr[i].b.x, arr[i].b.y);
    }
}