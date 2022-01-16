#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}
int main(void) {
    int n, m, p, elements = 0, i;
    double *arr;
    srand(time(NULL));

    printf("Initial size: ");
    scanf("%d", &n);
    elements += n;
    arr = (double*)malloc(elements*sizeof(double));
    if (arr == NULL) {
        printf("Can not malloc\n");
        return -1;    }
    for (i=0; i<elements; i++) {
        arr[i] = randomReal(0.0, 1.0);
    }

    // for (i=0; i<elements; i++) {
    //     printf("%.4f ", arr[i]);
    // }
    // putchar('\n');

    printf("Elements to add on resize 1: ");
    scanf("%d", &m);
    elements += m;
    arr = (double*)realloc(arr, elements*sizeof(double));
    if (arr == NULL) {
        printf("Can not realloc\n");
        return -2;
    }
    for (; i<elements; i++) {
        arr[i] = randomReal(1.0, 2.0);
    }

    // for (i=0; i<elements; i++) {
    //     printf("%.4f ", arr[i]);
    // }
    // putchar('\n');

    printf("Elements to add on resize 2: ");
    scanf("%d", &p);
    elements += p;
    arr = (double*)realloc(arr, elements*sizeof(double));
    if (arr == NULL) {
        printf("Can not realloc\n");
        return -3;
    }
    for (; i<elements; i++) {
        arr[i] = randomReal(2.0, 3.0);
    }

    for (i=0; i<elements; i++) {
        printf("%.4f ", arr[i]);
    }
    putchar('\n');

    free(arr);

    return 0;
}