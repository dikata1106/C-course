#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void printStop(int i){
    printf("I don't want to stop!\n");
}

void stopFun(){
    printf("I;dont want to stop - TSTP!\n");
}

int main(void){
    struct sigaction sa;
    sa.sa_handler = printStop;
    sigaction(SIG, &sa, NULL);
    
    //
    signal(SIGTSTP, stopFun);
    while (1){
        printf("Hello\n");
        sleep(1);
    }
}