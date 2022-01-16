#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


typedef enum { APPLE, ORANGE, MILK, RAKIA } pruduct_name;

typedef struct  {
    double price;
    unsigned barcode;
    pruduct_name prod;

} pruduct_t;

void onClosing(){
    printf("\bBye bye\n");
    exit(EXIT_SUCCESS);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = onClosing;
    sigaction(SIGINT, &sa, NULL);
   // signal(SIGINT, onClosing);
    while (1){
        printf("Hello\n");
        sleep(1);
    }
    return 0;
}