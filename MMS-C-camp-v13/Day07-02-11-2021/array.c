#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#include <unistd.h>

#define SIZE(array) (sizeof(array)/sizeof(array[0]))
#define COUNT 10

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int n){
    for (int j = 0; j < n; j++){
        for (int i = 0; i < n - 1 - j; i++){
            if (arr[i] < arr[i + 1]){
                swap(arr + i, arr + i + 1);
            }
        }
    }
}


int sumArray(int* arr, int n){
    int sum = 0;
    for (int i = 0; i < n; i++){
        sum += *(arr+i);
    }
    return sum;
}

int minElementI(int* arr, unsigned n){
    if (n == 0){
        return -1;
    }
    int minIndex = 0; 
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    return minIndex;
}

int minElement(int* arr, int n){

}

int maxElement(int* arr, int n){
    
}

double average(int* arr, int n){

}

int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int main(void){
    srand(time(NULL));
    int numbers[COUNT];
 
    for (int i = 0; i < SIZE(numbers); i++){
        *(numbers + i) = rand() % 10;
    }

    for (int i = 0; i < SIZE(numbers); i++){
        printf("%d ", *(numbers + i));
    }
    
    qsort(numbers, COUNT, sizeof(int), compare);
    
    putchar('\n');
    for (int i = 0; i < SIZE(numbers); i++){
        printf("%d ", *(numbers + i));
    }
    putchar('\n');

    return 0;
}