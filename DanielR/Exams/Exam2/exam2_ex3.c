#include <stdio.h>

void rec(char* c, int n, int i) {
    if(i == n)
        return;
    if(i%2 == 1) {
        switch(c[i]) {
            case '0':
                c[i] = '!';
                break;
            case '1':
                c[i] = '#';
                break;
            case '2':
                c[i] = '/';
                break;
            case '3':
                c[i] = '~';
                break;
            case '4':
                c[i] = '=';
                break;
            case '5':
                c[i] = '\'';
                break;
            case '6':
                c[i] = '\\';
                break;
            case '7':
                c[i] = '>';
                break;
            case '8':
                c[i] = '.';
                break;
            case '9':
                c[i] = ',';
                break;
            default:
                break;
        }
    } else {
        c[i] += 17;
    }
    return rec(c, n, i+1);
}

int main(void) {
    int numberOfDigits, i;
    char number[500];
    printf("Introduce number of digits (1..500): ");
    scanf("%d", &numberOfDigits);
    printf("Introduce number for substitution:\n");
    for (i=0; i<numberOfDigits; i++) {
        scanf(" %c", &number[i]);
    }
    rec(number, numberOfDigits, 0);
    for (i=0; i<numberOfDigits; i++) {
        printf("%c", number[i]);
    }
    putchar('\n');
    return 0;
}