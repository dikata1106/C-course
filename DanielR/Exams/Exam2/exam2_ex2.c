#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>



struct stu_d {
    char c1;
    int i[3];
    char c2;
};

struct stu_n {
    char c;
    struct stu_d a;
};




int main(void) {

    printf("stu_d = %ldB\n", sizeof(struct stu_n));

    return 0;
}
