#include <stdio.h>
#include <stdlib.h>
#include "llist.h"
#include <time.h>

#define N 10

unsigned sumDigits(unsigned num){
    unsigned sum = 0;
    while (num != 0){
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

unsigned digitalRoot(unsigned num){
    if (num < 10){
        return num;
    }
    digitalRoot(sumDigits(num));
}

int compare(int a, int b){
    return digitalRoot(b) - digitalRoot(a);
}

int main(void){
    srand(time(NULL));
    node_t* list = NULL;
    for (int i = 0; i < N; i++){
        push(&list, rand() % 101);
    }
    print_list(list);
    mergeSort(&list, compare);
    printf("Sorted: ");
    print_list(list);
    listFree(&list);
    return 0;
}
