#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define SIZE(x) (sizeof(x)/sizeof(*x))

typedef struct {
    char title[200];
    int pages; 
} book;

void swap(void*, void*, size_t);
void bubbleSort(void*, int, size_t, int (*)(const void*,const void*));
void printBooks(book* arr, size_t n);
int compareBookPages(const void*, const void*);
int compareBookTitle(const void*, const void*);


int main(void){
    book books[] = {{"The C programming", 500},
                    {"Linux", 3004},
                    {"Analysis", 304},
                    {"C++ programming", 234} };
    bubbleSort(books, SIZE(books), sizeof(book), compareBookPages);
    printBooks(books, SIZE(books));
    
    book *a, b = {"Linux", 304};
    a = bsearch(&b, books, sizeof(book), SIZE(books), compareBookPages);

    if(a)
    printf("Title: %s, Pages: %d\n", a->title, a->pages);
    else
    printf("Not found!\n");
    return 0;
}

void printBooks(book* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("Title: %s, Pages: %d\n", arr[i].title, arr[i].pages);
    }
}

void swap(void* a, void* b, size_t size){
    char temp[size];
    memmove(temp, b, size);
    memmove(b, a, size);
    memmove(a, temp, size);
}

void bubbleSort(void* arr, int count, size_t size, int (*cmp)(const void*,const void*)){
    for (int j = 0; j < count; j++){
        int swapped = 0;
        for (int i = 0; i < (count - 1 - j)*size; i += size){
            if (cmp((void*)(arr + i), (void*)(arr + i + size)) > 0){
                swap(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if (!swapped){ 
            return;
        }
    }
}

int compareBookPages(const void* b1, const void* b2){
    return ((book*)b1)->pages - ((book*)b2)->pages;
}

int compareBookTitle(const void* b1, const void* b2){
    return strcmp(((book*)b1)->title, ((book*)b2)->title);
}