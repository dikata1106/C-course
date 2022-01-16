#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapg(void* a, void* b, size_t size){
    char temp[size];
    memmove(temp, b, size);
    memmove(b, a, size);
    memmove(a, temp, size);
}

typedef struct {
    char title[200];
    int pages; 
} book;


void bubbleSort(void* arr, int n, size_t size, int (*cmp)(const void*, const void*)){
    for (int j = 0; j < n; j++){
        int swapped = 0;
        for (int i = 0; i < (n - 1 - j)*size; i += size){
            if (cmp((void*)(arr + i), (void*)(arr + i + size)) > 0){
                swapg(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if (!swapped) return;
    }
}

int compareI(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int compare(const void* a, const void* b){
    return *(int*)b - *(int*)a;
}

int compareD(const void* a, const void* b){
    return *(double*)b - *(double*)a;
}

int compareBook(const void* a, const void* b){
    book* ba = (book*)a;
    book* bb = (book*)b;
    return strcmp(ba->title, bb->title);
}

int main(void){
    //char arr[] = {'a', 'z', 's', 'k', 'm', 'b', 'p', 'c'};
    int arr[] = { 1, 10, -3, 44, 3, -34, 1, 34, 100, -3 };
    double a[] = {3.24, 45.5, 345, 45, 0, -300, -34, 4.44, 3, 65.3};
    bubbleSort(a, 10, sizeof(double), compareD);
    book books[] = {{"AZagl2", 300}, {"BZagl1", 20}, {"AAZagl3", 567}};
    bubbleSort(books, 3, sizeof(book), compareBook);
    for (int i = 0; i < 3; i++){
        printf("%s ", books[i].title);
    }
    putchar('\n');
    return 0;   
}