// Daniel Ruskov 29/10/2021
// This program does not control the errors of wrong inputs
#include <stdio.h>

int main(void) {

    int N, i, j, pipes;
    char op;

    printf("Enter N: ");
    scanf("%d", &N);
    printf("Enter option (a, b, c, d, e): ");
    scanf(" %c", &op);

    switch(op) {
        case 'a':
            for(i=0; i<N; i++) {
                for(j=0; j<N; j++) {
                    putchar('*');
                }
                putchar('\n');
            }   
            break;
        case 'b':
            for(i=0; i<N; i++) {
                for(j=0; j<i+1; j++) {
                    putchar('$');
                }
                putchar('\n');
            }
            break;
        case 'c':
            for(i=0; i<N; i++) {
                for(j=0; j<N; j++) {
                    if(j==0 || j==N-1) {
                        if(i==0 || i==N-1) {
                            putchar('+');
                        } else {
                            putchar('|');
                        }
                    } else {
                        putchar('-');
                    }
                }
                putchar('\n');
            } 
            break;
        case 'd':
            N++;
            for(i=0; i<N; i++) {
                for(j=N-i; j>0; j--) {
                    putchar(' ');
                }
                for(j=0; j<i; j++) {
                    putchar('*');
                }
                printf(" | ");  // putchar('|');
                for(j=0; j<i; j++) {
                    putchar('*');
                }
                for(j=N-i; j>0; j--) {
                    putchar(' ');
                }
                putchar('\n');
            }
            break;
        case 'e':
            pipes = N&1==1 ? (N>>2)+1 : N>>2;
            for(i=0; i<N; i++) {
                for(j=0; j<=N<<1; j++) {
                    if (i==0 || i==N-1 || j==0 || j==N<<1) {
                        putchar('*');
                    } else {
                        putchar('/');
                    }
                }
                if(i!=pipes) {
                    for(j=0; j<N; j++) {
                        putchar(' ');
                    }
                } else {
                    for(j=0; j<N; j++) {
                        putchar('|');
                    }
                }
                for(j=0; j<=N<<1; j++) {
                    if (i==0 || i==N-1 || j==0 || j==N<<1) {
                        putchar('*');
                    } else {
                        putchar('/');
                    }
                }
                putchar('\n');
            }
            break;
        default:
            printf("Invalid option.\n");
            break;
    }
    return 0;
}