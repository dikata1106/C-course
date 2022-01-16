
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXSIZE 1000

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int maxNum(int* arr, int n){
    int max = arr[0];
    for (int i = 1; i < n; i++){
        max = max > arr[i] ? max : arr[i]; 
    }
    return max;
}

int minNum(int* arr, int n){
    int min = arr[0];
    for (int i = 1; i < n; i++){
        min = min < arr[i] ? min : arr[i]; 
    }
    return min;
}

void printArray(int* arr, int n){
    printf("Sizeof: %lu\n", sizeof(arr));
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
}

void printArrayV(const void* ptr, int n, int flag){
    if (flag == 1){
        int* arr = (int*)ptr;
        printArray(arr, n);
    } 
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

void printNum(int num, int (*f)(int)){
    int result = f(num);
    printf("Value = %d\n", result);
}

int main(void){
    int arr[10000];
    int n;
    int (*f)(int*, int);
    printf("Sizeof f: %ld\n", sizeof(f));
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        arr[i] = 1 +rand() % 10;
    }
    printArrayV(&arr, n, 1);
    qsort(arr, sizeof(int), n, compare);
    printArray(arr, n);
    printf("Max num: %d\n", f(arr, n));
    f = minNum;
    printf("Min num: %d\n", f(arr, n));
    return 0;
}
