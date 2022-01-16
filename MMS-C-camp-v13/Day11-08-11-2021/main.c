#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#define SIZE 10

int* getArray(){
    int* arr = (int*)malloc(SIZE*sizeof(int));
    arr[0] = 10; arr[2] = 30;
    arr[3] = 50; arr[5] = 60;
    arr[4] = 10; arr[6] = 30;
    arr[4] = 10; arr[7] = 30;
    arr[8] = 10; arr[9] = 30;
    return arr;
}


int main(void){
    srand(time(NULL));
    int* nums = (int*)malloc(5 * sizeof(int));

    printf("Pinter to nums: %p\n", nums);
    if (nums == NULL){
        printf("Can't allocate memory!\n");
        return 1;
    }

    for (int i = 0; i < 5; i++){
        i[nums] = rand() % 10;
    }

    nums = realloc(nums, 10 * sizeof(int));
    printf("Pinter to nums after realloc: %p\n", nums);
    for (int i = 5; i < 10; i++){
        i[nums] = rand() % 10;
    }


    for (int i = 0; i < 10; i++){
        printf("%d ", *(nums + i));  // nums[i] === *(num + i) === i[nums] == *(i + num)
    }
    putchar('\n');
    free(nums);
    return 0;
}