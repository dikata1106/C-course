#include <stdarg.h>
#include <stdio.h>
#include <string.h>

double average(int, ...);

double average(int cnt, ...) {
    double avg = 0.0;
    int i;
    va_list args;
    va_start(args, cnt);
    for (i=0; i<cnt; i++)
        avg += va_arg(args, double);
    va_end(args);
    return avg /= cnt;  // assert cnt != 0
}

void printArgs(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    while(*fmt) {
        // CANNOT DECLARE VARIABLES IN SWITCH CASE
        switch(*fmt++) {
            case 'd':
                printf("%d\n", va_arg(args, int));
                break;
            case 'c':
                printf("%c\n", (char)va_arg(args, int));
                break;
            case 'f':
                printf("%f\n", va_arg(args, double));
                break;
            case 's':
                printf("%s\n", va_arg(args, char*));
                break;
            default:
                break;
        }
    }
    va_end(args);
}

/* To return char for a value.
*  For example '2' is returned for 2.
*  'A' is returned for 10. 'B' for 11
*/
char intToChar(int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strReverse(char *str) {
    int len = strlen(str), i;
    char temp;
    for (i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a given decimal number to a base 'b'
char* decToBin(char res[], int num) {
    int index = 0;
    while (num > 0) {                       // Convert input number is given base by repeatedly dividing it by base and taking remainder
        res[index++] = intToChar(num % 2);
        num /= 2;
    }
    res[index] = '\0';
    strReverse(res);                             // Reverse the result
    return res;
}

void printNumber(char* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    char bin[32];
    while(*fmt) {
        // CANNOT DECLARE VARIABLES IN SWITCH CASE
        switch(*fmt++) {
            case 'd':
                printf("DEC: %d\n", va_arg(args, int));
                break;
            case 'b':
                printf("BIN: %s\n", decToBin(bin, va_arg(args, int)));
                break;
            case 'o':
                printf("OCT: %o\n", va_arg(args, int));
                break;
            case 'x':
                printf("HEX: %x\n", va_arg(args, int));
                break;
            default:
                break;
        }
    }
    va_end(args);
}

int main(){
    // printf("%f\n", average(10, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0));
    // printArgs("dsfdsc", 10, "abcd", 3.14, -4, "Hello", 'R');
    printNumber("dbox", 29, 29, 29, 29);
    return 0;
}