#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#define COUNT 10
#define SIZE(a) (sizeof(a)/sizeof(*a))

int randomInt(int , int);
void quicksort(int*, int ,int);
void generateIntArr(int*, int);
void printIntArr(int*, int);
int RetValState = -1;    // 0 cycling, 1 out of range
int ex2_rec_aux(int*, int, int, int);
int ex2_rec(int*, int, int);
void (*getSorting(char*))(void*, size_t, size_t, int(*)(const void*, const void*));
void swapUni(void*, void*, size_t);
void bubbleSort(void*, size_t, size_t, int (*cmp)(const void*,const void*));
int compare(const void*, const void*);

int main(void) {

    int rval, start, a[COUNT], *b, c[] = {5, 23, 77, 123, 681, 9, 772, 16}, d[] = {72, 14, 90, 27, 11, 63, 81, 52};
    srand(time(NULL));
    
    generateIntArr(a, COUNT);
    printIntArr(a, COUNT);
    printf("--> quickSort --> ");
    quicksort(a, 0, COUNT-1);
    printIntArr(a, COUNT);
    putchar('\n');
    putchar('\n');
    putchar('\n');

    start = randomInt(0, SIZE(a)-1);
    printIntArr(a, SIZE(a));
    printf("with start on index %d\n", start);
    rval = ex2_rec(a, SIZE(a), start);
    if (rval < 0) {
        printf("ERROR\n");
    } else {
        if (RetValState == 0) {
            printf("cycling\n");
        } else {
            printf("goes out of range\n");
        }
        printf("Return value: %d hops\n", rval);
    }
    putchar('\n');

    start = -1;
    printIntArr(b, 0);
    printf("with start on index %d\n", start);
    rval = ex2_rec(b, SIZE(b), start);
    if (rval < 0) {
        printf("ERROR\n");
    } else {
        if (RetValState == 0) {
            printf("cycling\n");
        } else {
            printf("goes out of range\n");
        }
        printf("Return value: %d hops\n", rval);
    }
    putchar('\n');

    start = 4;
    printIntArr(c, SIZE(c));
    printf("with start on index %d\n", start);
    rval = ex2_rec(c, SIZE(c), start);
    if (rval < 0) {
        printf("ERROR\n");
    } else {
        if (RetValState == 0) {
            printf("cycling\n");
        } else {
            printf("goes out of range\n");
        }
        printf("Return value: %d hops\n", rval);
    }
    putchar('\n');
    
    start = 15;
    printIntArr(c, SIZE(c));
    printf("with start on index %d\n", start);
    rval = ex2_rec(c, SIZE(c), start);
    if (rval < 0) {
        printf("ERROR\n");
    } else {
        if (RetValState == 0) {
            printf("cycling\n");
        } else {
            printf("goes out of range\n");
        }
        printf("Return value: %d hops\n", rval);
    }
    putchar('\n');

    start = 0;
    printIntArr(d, SIZE(d));
    printf("with start on index %d\n", start);
    rval = ex2_rec(d, SIZE(d), start);
    if (rval < 0) {
        printf("ERROR\n");
    } else {
        if (RetValState == 0) {
            printf("cycling\n");
        } else {
            printf("goes out of range\n");
        }
        printf("Return value: %d hops\n", rval);
    }
    putchar('\n');
    putchar('\n');

    void (*f)(void*, size_t, size_t, int(*)(const void*, const void*));
    f = getSorting("qsort");

    printIntArr(c, SIZE(c));
    printf("--> calling qsort --> ");
    // getSorting("qsort")(c, SIZE(c), sizeof(int), compare);
    f(c, SIZE(c), sizeof(int), compare);
    printIntArr(c, SIZE(c));
    putchar('\n');

    printIntArr(d, SIZE(d));
    printf("--> calling bubbleSort --> ");
    getSorting("bubbleSort")(d, SIZE(d), sizeof(int), compare);
    printIntArr(d, SIZE(d));
    putchar('\n');

    return 0;
}


int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

void generateIntArr(int* a, int n) {
    int i;
    for(i=0;i<n;i++)
        a[i] = randomInt(0, 10);
    return;
}

void printIntArr(int* a, int n) {
    int i;
    printf("[ ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("] ");
    return;
}

void quicksort(int *arr, int first,int last) {
    int i, j, pivot, temp;

    if (first < last) {
        pivot = first;
        i = first;
        j = last;

        while (i < j) {
            while (arr[i] <= arr[pivot] && i < last)
                i++;
            while (arr[j] > arr[pivot])
                j--;
            if (i < j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        quicksort(arr, first, j - 1);
        quicksort(arr, j + 1, last);
    }
}

int ex2_rec_aux(int* arr, int size, int i, int start) {
    if (i == start) {
        RetValState = 0;
        return 0;
    }
    if (i<0 || i>= size){
        RetValState = 1;
        return 0;
    }
    int tmp = arr[i], sum = 0;
    printf("%d(%d)->", arr[i], i);
    while(tmp) {
        sum += tmp%10;
        tmp /= 10;
    }
    (sum % 2) ? (i -= 2) : (i += 3);
    return 1 + ex2_rec_aux(arr, size, i, start);
}

int ex2_rec(int* arr, int size, int start) {
    if (arr == NULL)
        return -1;
    if (start < 0 || start >= size)
        return -2;
    // assert all arr[i] >= 0
    int i = start, tmp = arr[start], sum = 0;
    printf("%d(%d)->", arr[start], start);
    while(tmp) {
        sum += tmp%10;
        tmp /= 10;
    }
    (sum % 2) ? (i -= 2) : (i += 3);
    return ex2_rec_aux(arr, size, i, start);
}

void (*getSorting(char* fname))(void*, size_t, size_t, int(*)(const void*, const void*)) {
    if (!strcmp(fname, "qsort"))
        return qsort;
    if (!strcmp(fname, "bubbleSort"))
        return bubbleSort;
    return NULL;
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

int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
