#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 100
#define N 10

typedef struct {
    char title[150];
    char autor[100];
    double price;
    int pages;
} book;

int randomInt(int,int);
double randomReal(double,double);
void bubbleSort(void*,size_t,size_t,int(*)(const void*,const void*));
void swapUni(void*,void*,size_t);
int compareBookT(const void*, const void*);
int compareBookP(const void*, const void*);

int sum(int a, int b){
    return a + b;
}
int sub(int a, int b){
    return a - b;
}

int (*f[2])(int,int) = {sum, sub};
int (*oper(int a))(int, int){
    if (a == -1){
        return f[1];
    }
    return f[0];
}

int main(void){
    int a = oper(-1)(3, 10);
    printf("a = %d\n", a);
    /*srand(time(NULL));
    book books[COUNT];
    for (int i = 0; i < COUNT; i++){
        books[i].title[0] = randomInt('A', 'Z');
        books[i].autor[0] = randomInt('A', 'Z');
        for (int k = 1; k < N; k++){
            books[i].title[k] = randomInt('a', 'z');
            books[i].autor[k] = randomInt('a', 'z');
        }
        books[i].title[N-1] = '\0';
        books[i].autor[N-1] = '\0';
        books[i].pages = randomInt(10, 11);
        books[i].price = randomReal(1.0, 100.0);
    }

    bubbleSort(books, COUNT, sizeof(book), compareBookT);
    bubbleSort(books, COUNT, sizeof(book), compareBookP);

    for (int i = 0; i < COUNT; i++){
        printf("Title: %s, ", books[i].title);
        printf("Autor: %s, ", books[i].autor);
        printf("Pages: %4d, ", books[i].pages);
        printf("Price: %3.2lf lv\n", books[i].price);
    }*/
    return 0;
}

int compareBookP(const void* a, const void* b){
    return ((book*)a)->pages - ((book*)b)->pages;
}

int compareBookT(const void* a, const void* b){
    return strcmp(((book*)a)->title, ((book*)b)->title);
}

int randomInt(int min, int max){
    return min + rand() % (max - min + 1);
}

double randomReal(double min, double max){
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void swapUni(void* a, void *b, size_t size){
    char temp[size];
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
