#include <stdio.h>
#include <stdlib.h>

struct myDynamicArray {
    int *values;
    int capacity;
    int curElemCount;
};

struct myDynamicArray createDynamicArray(int initialSize) {
    struct myDynamicArray arr;
    arr.values = (int*)malloc(sizeof(int)*initialSize);
    if (!arr.values) {
        printf("ERROR: malloc\n");
        arr.curElemCount = arr.capacity = 0;
        exit(EXIT_FAILURE);
    }
    arr.curElemCount = 0;
    arr.capacity = initialSize;
    return arr;
}

void printArr(struct myDynamicArray arr) {
    int i;
    for (i=0; i<arr.curElemCount; i++) {
        printf("%d ", arr.values[i]);
    }
    putchar('\n');
}

void resize(struct myDynamicArray *arr, int newCapacity) {
    int *oldValues = arr->values;
    arr->values = (int *)realloc(oldValues, newCapacity);
    if (!arr->values) {
        return;
    }
}

void pushElem(struct myDynamicArray *arr, int newElem) {
    if (arr->curElemCount == arr->capacity) {

    }
    arr->values[arr->curElemCount] = newElem;
    arr->curElemCount++;
}

int main(void) {
    struct myDynamicArray arr1 = createDynamicArray(100);
    //arr1.values = {100, 120, 351, 12412, 24142};
    arr1.curElemCount = 5;
    printArr(arr1);
    free(arr1.values);
    exit(EXIT_SUCCESS);
}