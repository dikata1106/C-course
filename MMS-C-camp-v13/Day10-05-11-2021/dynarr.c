#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define N 5
#define M 5

struct s {
    char a;
    char c;
    int b;
};

typedef union {
    uint8_t data;
    struct {
        uint8_t b0 : 1,
                b1 : 1,
                b2 : 1,
                b3 : 1,
                b4 : 1,
                b5 : 1,
                b6 : 1,
                b7 : 1;
    } bit;
} mask;

typedef struct {
    unsigned bf : 4;
} bitf;

typedef struct {
    double x[2];
} str;

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

union {
    float f;
    uint32_t u;
} fu;

union {
    uint8_t mask;
    struct {
    uint8_t b0 : 1,
            b1 : 1,
            b2 : 1,
            b3 : 1,
            b4 : 1,
            b5 : 1,
            b6 : 1,
            b7 : 1;
    } bit;
} u;


struct {
    int a : 1;
    int b: 1;
    int d : 1;
    int c;
   
} s;

char* getRandString(){
    char *str = (char*)malloc(5);
    strcpy(str, "abcd");
    return str;
}

union {
    uint16_t word;
    struct {
        uint8_t byte1;
        uint8_t byte2;
    };
} un;

int main(int argc, char **argv){

    un.byte1 = 0xff;
    un.byte2 = 0xaa;
    printf("%x\n", un.word);
    /*int** a;
    a = (int**)malloc( N * sizeof(int*));

    for (int i = 0; i < N; i++){
        *(a+i) = (int*)malloc(M*sizeof(int));
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            *(*(a+i)+j) = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", a[i][j]);
        }
        putchar('\n');
    }

    for (int i = 0; i < N; i++){
        free(*(a + i));
    }
    free(a);*/
    return 0;
}