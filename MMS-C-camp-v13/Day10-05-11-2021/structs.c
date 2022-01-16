#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#define CHECKBIT(mask, bit) (!!((mask) & (1 << (bit))))
struct stu_a {
    int i;
    char c;
};

struct stu_b {
    long l;
    char c;
};

struct stu_c {
    int i;
    long l;
    char c;
};

struct stu_d {
    long l;
    int i;
    char c;
};

struct stu_e {
    double d;
    int i;
    char c;
};

struct stu_f {
    int i;
    double d;
    char c;
};


void printNumLn(int n){
    printf("Num = %d\n", n);
}

void printNum(int n){
    printf("Num = %d", n);
}

void (*funRet(void))(int){
    if (rand() % 2 == 0){
        return printNum;
    }
    return printNumLn;
}
void swapUni(void*, void*,size_t);
void bubbleSort(void*,size_t,size_t,int (*)(const void*,const void*));

void (*getSorting(const char* str))(void*,size_t,size_t,int(*)(const void*, const void*)){
    if (!strcmp(str, "qsort")){
        return qsort;
    }
    if (!strcmp(str, "bubble sort")){
        return bubbleSort;
    }
    return NULL;
}

int compare(const void* a, const void* b){
    return *(int*)a - *(int*)b; 
}

typedef struct {
    char c1;
    char c2;
    int i;
} str;

struct point {
    long x;
    int y;
    int z;
};

struct stu_g {
    struct point p1;
    int i;
    struct point p2;
};


union {
    uint16_t word;
    struct {
        uint8_t byte0;
        uint8_t byte1;
    };
} u;

typedef union {
    uint8_t a;
    uint16_t b;
} myunion;

union {
    float f;
    uint32_t u;
} uf;

union {
    int num;
    uint8_t byte[4];
} unum;

struct {
    unsigned a : 3;
    unsigned b : 3;
    unsigned c : 30;
    unsigned d : 2;
} sb;

typedef union {
    uint8_t value;
    struct {
        uint8_t bit0 : 1,
                bit1 : 1,
                bit2 : 1,
                bit3 : 1,
                bit4 : 1,
                bit5 : 1,
                bit6 : 1,
                bit7 : 1;
    };
} OUTREG;

typedef union {
    float value;
    struct {
        uint32_t m : 31,
                sign : 1;
    };
} OUTREG1;

// argc - arguments count, agrv - arguments values
int main(int argc, char *argv[]){
    int a = 10;
    uint64_t *p = (void*)(-1L);
    printf("%ld\n", *p);
    if (argc < 2){
        printf("Invalid aguments!\n");
        return 1;
    }
    int sum = 0;
    for (int i = 1; i < argc; i++){
        sum += atoi(argv[i]);
    }
    printf("Sum = %d\n", sum);
    return 0;
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
void swapUni(void* a, void *b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}