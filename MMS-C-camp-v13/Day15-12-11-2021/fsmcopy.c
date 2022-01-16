#include <stdio.h>

typedef enum { EMPTY, N, NA, NAN, NANO } nano_st;

int containsNano(char* str){
    nano_st state = EMPTY;
    while (*str){
        switch (state)
        {
        case EMPTY:
            if (*str == 'n'){
                state = N;
            }
            break;
        case N:
            if (*str == 'a'){
                state = NA;
            } else if (*str == 'n'){
                // stay here
            } else {
                state = EMPTY;
            }
            break;
        case NA:
            if (*str == 'n'){
                state = NAN;
            } else {
                state = EMPTY;
            }
            break;
        case NAN:
            if (*str == 'o'){
             //   state = NANO;
                return 1;
            } else if (*str == 'n'){
                state = N;
            } else {
                state = EMPTY;
            }
            break;
        }
        str++;
    }
    return 0;
}

int countNano(char* str){
    int cnt = 0;
    nano_st state = EMPTY;
    while (*str){
        switch (state)
        {
        case EMPTY:
            if (*str == 'n'){
                state = N;
            }
            break;
        case N:
            if (*str == 'a'){
                state = NA;
            } else if (*str == 'n'){
                // stay here
            } else {
                state = EMPTY;
            }
            break;
        case NA:
            if (*str == 'n'){
                state = NAN;
            } else {
                state = EMPTY;
            }
            break;
        case NAN:
            if (*str == 'o'){
                state = NANO;
                cnt++;
            } else if (*str == 'n'){
                state = N;
            } else {
                state = EMPTY;
            }
            break;
        case NANO:
            if (*str == 'n'){
                state = N;
            } else {
                state = EMPTY;
            }
            break;
        }
        str++;
    }
    return cnt;
}


int main(void){
    printf("%d\n", countNano("nanonanonano"));
    return 0;
}