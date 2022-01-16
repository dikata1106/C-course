#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define ARR_LEN(a) (sizeof(a)/sizeof(*a))

int BSAux(int *arr, int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return BSAux(arr, l, mid - 1, x);
        return BSAux(arr, mid + 1, r, x);
    }
    return -1;
}

int binarysearch(int *array, int size, int target) {
    return array == NULL ? -2 : BSAux(array, 0, size-1, target);
}

int main(void) {

    int key = 10, *a, b[] = {}, c[] = {1}, d[] = {10}, e[] = {1, 3, 4, 4, 8, 11, 11, 14}, f[] = {1, 3, 4, 4, 10, 11, 11, 14};

    printf("Return value: %d searching %d in a = NULL\n", binarysearch(a, ARR_LEN(a), key), key);
    printf("Return value: %d searching %d in b = {}\n", binarysearch(b, ARR_LEN(b), key), key);
    printf("Return value: %d searching %d in c = {1}\n", binarysearch(c, ARR_LEN(c), key), key);
    printf("Return value: %d searching %d in d = {10}\n", binarysearch(d, ARR_LEN(d), key), key);
    printf("Return value: %d searching %d in e = {1, 3, 4, 4, 8, 11, 11, 14}\n", binarysearch(e, ARR_LEN(e), key), key);
    printf("Return value: %d searching %d in f = {1, 3, 4, 4, 10, 11, 11, 14}\n", binarysearch(f, ARR_LEN(f), key), key);

    return 0;
}