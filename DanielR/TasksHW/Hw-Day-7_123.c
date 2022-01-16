#include <stdio.h>

#define SIZE(array) (sizeof(array)/sizeof(*array))

void printArr(int* arr, int n) {
    int i;
    printf("Length=%d, elements=[ ", n);
    for(i=0; i<n; i++)
        printf("%d ", *(arr+i));
    printf("]\n");
    return;
}

int secondMax(int* arr, size_t n, int* secondMax){
    int firstMax, i;
    if (n<2) {
        *secondMax = 0;
        return -1;
    }
    firstMax = *secondMax = *arr;
    for(i=0; i<n; i++) {
        if(arr[i] > firstMax)        {
            *secondMax = firstMax;
            firstMax = arr[i];
        } else if (arr[i] > *secondMax && arr[i] < firstMax) {
            *secondMax = arr[i];
        }
    }
    if (firstMax == *secondMax) {
        return -2;
    }
    return 0;
}

unsigned sumArrayDigits(int* arr, size_t n) {
    int i = 0, tmp;
    unsigned sum = 0;
    // assert that all numbers are positive
    while (i<n) {
        tmp = arr[i];
        while (tmp!=0) {
            sum += tmp%10;
            tmp /= 10;
        }
        i++;
    }
    return sum;
}

int sum(int* arr, int n) {
    int i = 0, sum = 0;
    while (i<n) {
        sum += arr[i];
        i++;
    }
    return sum;
}

void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)) {
    printf("arrayEvaluate = %d\n\n", f(arr, n));
}

int main(void) {

    int val, sm, a[] = {1, 15, 22, 22}, b[] = {1, 5, 2, 3}, c[] = {2, 4}, d[] = {24}, e[] = {2, 2, 2}, f[] = {};
    
    printArr(a, SIZE(a));
    val = secondMax(a, SIZE(a), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(a, SIZE(a)));
    arrayEvaluate(a, SIZE(a), sum);

    printArr(b, SIZE(b));
    val = secondMax(b, SIZE(b), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(b, SIZE(b)));
    arrayEvaluate(b, SIZE(b), sum);

    printArr(c, SIZE(c));
    val = secondMax(c, SIZE(c), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(c, SIZE(c)));
    arrayEvaluate(c, SIZE(c), sum);

    printArr(d, SIZE(d));
    val = secondMax(d, SIZE(d), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(d, SIZE(d)));
    arrayEvaluate(d, SIZE(d), sum);

    printArr(e, SIZE(e));
    val = secondMax(e, SIZE(e), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(e, SIZE(e)));
    arrayEvaluate(e, SIZE(e), sum);

    printArr(f, SIZE(f));
    val = secondMax(f, SIZE(f), &sm);
    printf("secondMax = %d, Return value: %d\n", sm, val);
    printf("sumArrayDigits = %d\n", sumArrayDigits(f, SIZE(f)));
    arrayEvaluate(f, SIZE(f), sum);

    return 0;
}