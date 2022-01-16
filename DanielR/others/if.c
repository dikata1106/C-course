#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i, cnt = 0;
    clock_t start, finish;
    start = clock();
    for(i=0; i<1000000; i++)
    //    if(i%2 == 0)
    //        cnt++;
    //    cnt += (i%2 == 0); // ? 1 : 0;
    //    cnt = i / 2;
        cnt = i>>1;
    finish = clock();
    printf("%ld\n", finish-start);
    return 0;
}