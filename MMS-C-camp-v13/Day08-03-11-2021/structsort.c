#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>

#define COUNT 100

typedef struct  {
    char title[100];
    char autor[100];
    int pages;
    double price;
} book;

int randInt(int,int);
double randReal(double,double);
void printBooks(book*, size_t);

int comparePages(const void* a, const void* b){
    return ((book*)a)->pages - ((book*)b)->pages;
}

int compareTitle(const void* a, const void* b){
    return strcmp(((book*)a)->title, ((book*)b)->title);
}

void swapUni(void* a, void *b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

int compareInt2(int a, int b){
    return b - a;
}

void bubbleSort(void* arr, size_t nmemb, size_t size, int (*cmp)(const void*,const void*)){
    for (int j = 0; j < nmemb; j++){
        int swapped = 0;
        for (int i = 0; i < (nmemb - j - 1) * size; i += size){
            if (cmp(arr + i, arr + i + size) > 0){
                swapUni(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if (!swapped){
            return; // sorted break
        }
    }
} 

int main(void){
    srand(time(NULL));
    book books[COUNT];
    for (int i = 0; i < COUNT; i++){
        books[i].pages = randInt(1, 2);
        books[i].price = randReal(2.20, 90.50);
        int cnt = randInt(5, 10);
        books[i].title[0] = randInt('A', 'Z');
        books[i].autor[0] = randInt('A', 'Z');
        for (int j = 1; j < cnt; j++){
            books[i].title[j] = randInt('a', 'z');
            books[i].autor[j] = randInt('a', 'z');
        }
        books[i].title[cnt] = 0;
        books[i].autor[cnt] = 0;
    }
    qsort(books, COUNT, sizeof(book), compareTitle);
    qsort(books, COUNT, sizeof(book), comparePages);
    printBooks(books, COUNT);
    return 0;
}

void printBooks(book* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("Title: %10s, ", arr[i].title);
        printf("Autor: %10s, ", arr[i].autor);
        printf("Price: %3.2lf lv, ", arr[i].price);
        printf("Pages: %d\n", arr[i].pages);
    }
}

int randInt(int min, int max){
    return min + rand() % (max - min + 1); 
}

double randReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}