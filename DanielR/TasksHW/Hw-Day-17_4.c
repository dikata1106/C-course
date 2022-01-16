#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define TRUE !0

void main(int argc, char **argv) {
    
    signal(SIGTSTP, NULL);  //^z
    signal(SIGINT, NULL);   //^c

    // with KILL signal will stop anyways, cause is sent to OS, not to the process

    // struct sigaction sa;
    // sa.sa_handler = NULL;
    // sigaction(SIGINT, &sa, NULL);
    // sigaction(SIGTSTP, &sa, NULL);

    while (TRUE) {
        printf("MMS C Camp\n");
        usleep(500000);
    }
    exit(EXIT_SUCCESS);
}