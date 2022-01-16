#include <stdio.h>

unsigned long getFib(unsigned N) {
    if (N <= 2)
        return 1;
    else
        return getFib(N-1) + getFib(N-2);
}

int main(void) {
    unsigned N;
    scanf("%d", &N);
    printf("%lu\n", getFib(N));
    return 0;
}