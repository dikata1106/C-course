#include <stdio.h>


int sum(int a, int b){
    return a + b;
}

int sub(int a, int b){
    return a - b;
}

int mult(int a, int b){
    return a * b;
}

int div(int a, int b){
    return a / b;
}

void printNum(int a){
    printf("Number  = %d\n", a);
}

double avarage(int* arr, size_t n){
    return 0.0;
}

void printValue(int, int(*)(int));

int main(){
    int num = 10;
    printValue(num, twice);
    printValue(num, decrement);
    return 0;

}

void printValue(int a, int(*f)(int)){
    int result = f(a);
    printf("A = %d\n", result);
}

int twice(int a){
    return 2*a;
}

int decrement(int a){
    return --a;
}