#include <stdio.h>

#define SIZE(array) (sizeof(array)/sizeof(*array))

// Ex.1
void ex1(int* n, int* m, int* r, int* q) {
    *q = *n >> *m;
    *r = *n & ((1<<*m) - 1);
    return;
}

// Ex.2
char ex2(char c) {
    return ((c<='9' && c>='0') ? (c+'A'-'0') : ((c<='Z' && c>='A') ? (c | ' ') : ('\'')));
}

// Ex.3
void printArr(int* arr, int n) {
    int i;
    printf("Length=%d, elements=[ ", n);
    for(i=0; i<n; i++)
        printf("%d ", *(arr+i));
    printf("]\n");
    return;
}

// Ex.4
void inputIntArr(int* arr, int n) {
    printf("Insert %d ints into array:\n", n);
    int i;
    for(i=0; i<n; i++)
        scanf("%d", (arr+i));
    return;
}

// Ex.5
int getFromInput(int n) {
    scanf("%d", &n);
    return n;
}

int printAndReturn(int n) {
    printf("%d, ", n);
    return n;
}

int mySquare(int n) {
    return n*n;
}

void myMap(int* arr, int n, int (*f)(int)) {
    int i;
    for (i=0; i<n; i++) {
        arr[i] = f(arr[i]);
    }
    return;
}

int main(void) {
    // int n = 40, m = 4, r, q;
    // ex1(&n, &m, &r, &q);
    // printf("%d / (2^%d) = %d(q) and %d(r)\n", n, m, q, r);
    // char c[16] = {'A', 'B', 'C', '/','X', 'Y', 'Z', 'a', '_', 'z', '0', '1', '8', '9', '$', '\''};
    // printf("A B C / X Y Z a _ z 0 1 8 9 $ \\ \n");
    // for(n=0; n<16; n++)
    //     printf("%c ", ex2(c[n]));
    // putchar('\n');
    // int arr[10] = {3, 55, 2, 18, 5, 0, 14, 6, 1, 0};
    // int a[10];
    // inputIntArr(a, SIZE(a));
    // printArr(a, SIZE(a));

    int a[100], n;
    scanf("%d", &n);
    myMap(a, n, getFromInput);
    myMap(a, n, mySquare);
    myMap(a, n, printAndReturn);

    return 0;
}