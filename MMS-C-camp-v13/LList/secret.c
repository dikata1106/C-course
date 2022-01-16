#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { NON, N, NA, NAN, NANO } states_t;

int main(void){

    states_t s = NON;
    char st[100];
    char *str = st;
    printf("Enter string: ");
    fgets(st, 100, stdin);
    st[strlen(st) - 1] = '\0';
    int cnt = 0;
    while (*str){
        switch (s)
        {
        case NON:
            if (*str == 'n'){
                s = N;
            }
            break;
        case N:
            if (*str == 'a'){
                s = NA;
            } else if (*str == 'n'){
                // stay here
            } else {
                s = NON;
            }
            break;
        case NA:
            if (*str == 'n'){
                s = NAN;
            } else {
                s = NON;
            }
            break;
        case NAN:
            if (*str == 'o'){
                s = NANO;
                cnt++;
            } else if (*str == 'n'){
                s = N;
            } else {
                s = NON;
            }
            break;
        case NANO:
            if (*str == 'n'){
                s = N;
            } else {
                s = NAN;
            }
        }
        str++;
    }


    if (cnt != 0){
        printf("Found! - %d times\n", cnt);
    } else {
        printf("Not found!\n");
    }
    /*char pass[] = "Abcd1234";
    char input[100];
    printf("Enter password: ");
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = '\0';

    if (strncmp(pass, input, 100) == 0){
        printf("Welcome! This is secret info!...\n");
    } else {
        printf("Incorrent password!");
    }*/
    return 0;
}