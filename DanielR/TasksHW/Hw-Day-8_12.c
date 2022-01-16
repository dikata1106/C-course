#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>

#define COUNT 10

typedef struct {
    char title[150];
    char autor[100];
    int pages;
    double price;
} book;

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void generateBooks(book* b, size_t n) {
    int i, j, chars;
    for (i=0; i<COUNT; i++) {
        // printf("book %d ", i);
        b[i].pages = randomInt(5, 2000);
        b[i].price = randomReal(1.0, 1000.0);
        chars = randomInt(10, 20);
        b[i].title[0] = randomInt('A', 'Z');
        for(j=1; j<chars; j++) {
            b[i].title[j] = randomInt('a', 'z');
        }
        b[i].title[j] = '\0';
        chars = randomInt(10, 20);
        b[i].autor[0] = randomInt('A', 'Z');
        for(j=1; j<chars; j++) {
            b[i].autor[j] = randomInt('a', 'z');
        }
        b[i].autor[j] = '\0';
        // printf("initialized\n");
    }
    return;
}

void printBooks(book* arr, size_t n) {
    int i;
    for (i=0; i<n; i++) {
         printf("Title: %20s, Autor: %20s, Pages: %d,\tPrice: %.2lf\n", arr[i].title, arr[i].autor, arr[i].pages, arr[i].price);
    }
    return;
}

int compareTitle(const void* a, const void* b) {
    return strcmp((*((book*)a)).title, ((book*)b)->title);
}

int compareAutorRev(const void* a, const void* b) {
    return strcmp((*((book*)b)).autor, ((book*)a)->autor);
}

int comparePages(const void* a, const void* b) {
    return (*((book*)a)).pages - ((book*)b)->pages;
}

int comparePrice(const void* a, const void* b) {
    double p1 = (*((book*)a)).price, p2 = ((book*)b)->price;
    if (fabs(p1-p2) < (1e-5*fmax(p1, p2))) { //  a1 == a2
        return 0;
    } else if (p1<p2) {
        return -1;
    } else {
        return 1;
    }
}

void swapUni(void* a, void *b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
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

void* linearSearch(const void* key, void* arr, size_t nitems, size_t size, int (*cmp)(const void* a, const void* b)){
    for (int i = 0; i < nitems * size; i += size){
        if (cmp(arr + i, key) == 0){
            return arr + i;
        }
    }
    return NULL;
}

int binarysearch(int *array, int size, int target) {
    int mid = size / 2;
    if (size < 1) {
        return -1;
    }
    if (size == 1) {
        return array[0];
    }
    if (target == array[mid]) {
        return target;
    } else
    if (target < array[mid]) {
        binarysearch(array, mid, target);
    } else{
        binarysearch(array + mid, size - mid, target);
    }
}

int main(void) {
    book books[COUNT];
    srand(time(NULL));
    // printf("%ld\n", sizeof(book));
    generateBooks(books, COUNT);

    // qsort(books, COUNT, sizeof(book), comparePages);
    // qsort(books, COUNT, sizeof(book), compareTitle);
    // qsort(books, COUNT, sizeof(book), compareAutorRev);
    // qsort(books, COUNT, sizeof(book), comparePrice);
    // bubbleSort(books, COUNT, sizeof(book), comparePages);
    // bubbleSort(books, COUNT, sizeof(book), comparePrice);
    bubbleSort(books, COUNT, sizeof(book), compareTitle);
    // bubbleSort(books, COUNT, sizeof(book), compareAutorRev);
    // printBooks(books, COUNT);

    books[5].price = 20.5;
    // strcpy(books[5].title, "Jurassic Park");
    book tmp = {"Jurassic Park", "Key book for search", 538, 20.5};
    book* searched = linearSearch((void*)&tmp, books, COUNT, sizeof(book), comparePrice);
    if(searched != NULL) {
        printf("Book title with price 20.5 is %s\n", searched->title);
    } else {
        printf("No book with price 20.5 was found\n");
    }
    printBooks(books, COUNT);


    return 0;
}