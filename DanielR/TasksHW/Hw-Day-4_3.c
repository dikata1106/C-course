/* Daniel Ruskov Vangelov 29/10/2021
*  https://codeforwin.org/2018/05/10-cool-bitwise-operator-hacks-and-tricks.html
*  https://www.geeksforgeeks.org/convert-base-decimal-vice-versa/
*  https://www.rapidtables.com/convert/number/base-converter.html
*  The program can convert only positive numbers (without sign) in range 0 to 18,446,744,073,709,551,615. If it is bigger, will oberflow. 
*  The program does not verify if from/to base input is digit. If it is not a digit, would crash.
*  No functions as strtoull() and strlen() are used, only printf() and scanf()
*/
#include <stdio.h>
#include <ctype.h>

// Function to get the length of a tring without '\n'
int strLen(const char *str) {
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}

/* To return value of a char.
*  For example, 2 is returned for '2'.
*  10 is returned for 'A', 11 for 'B'
*/
int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return (int)c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return (int)(c & '_') - 'A' + 10;       // converting in uppercase
    } else if (c >= 'A' && c <= 'Z') {
        return (int)c - 'A' + 10;
    } else {
        printf("Invalid input character %c.\n", c);
        return -1;
    }
}

/* To return char for a value.
*  For example '2' is returned for 2.
*  'A' is returned for 10. 'B' for 11
*/
char intToChar(unsigned long long int num) {
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strReverse(char *str) {
    int len = strLen(str), i;
    char temp;
    for (i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}

// Function to convert a number from given base 'b' to decimal
unsigned long long int toDec(char *str, int base) {
    int len = strLen(str), i;
    unsigned long long int num = 0, power = 1, n;;
    for (i = len-1; i >= 0; i--) {      // Decimal equivalent is str[len-1]*1 + str[len-2]*base + str[len-3]*(base^2) + ...
        n = charToInt(str[i]);
        if (n < 0) {                     // if invalid char     
            return -1;
        } else if (n >= base) {         // A digit in input number must be less than number's base
           printf("Invalid Number. A digit in input number must be less than number's base.\n");
           return -1;
        } else {
            num += n * power;
            power *= base;
        }
        // printf("%llu, %llu, %llu\n", num, n, power);
    }
    return num;
}

// Function to convert a given decimal number to a base 'b'
char* fromDec(char res[], int base, unsigned long long int num) {
    int index = 0;
    while (num > 0) {                       // Convert input number is given base by repeatedly dividing it by base and taking remainder
        res[index++] = intToChar(num % base);
        num /= base;
    }
    res[index] = '\0';
    strReverse(res);                             // Reverse the result
    return res;
}

int main(void) {

    char strIn[65], strOut[65];     //size in bits of a max value undigned long long int (64bit) + '\0'
    int fromBase, toBase;
    unsigned long long int base10;

    printf("BASE CONVERTER\n");
    printf("==============\n");
    printf("Enter number: ");
    scanf("%s", strIn);
    printf("From base: ");
    scanf("%d", &fromBase);
    while (fromBase>36 || fromBase<2) {
        printf("WRONG BASE RANGE (2..36)\nFrom base: ");
        scanf("%d", &fromBase);   
    }
    printf("To base: ");
    scanf("%d", &toBase);
    while (toBase>36 || toBase<2) {
        printf("WRONG BASE RANGE (2..36)\nTo base: ");
        scanf("%d", &toBase);   
    }
    if ( (base10 = toDec(strIn, fromBase)) < 0) {   // convert and see for errors in input
        return -1;
    }
    if (fromBase == toBase) {
        printf("Result number: %s (base%d)\n", strIn, fromBase);
        return 0;
    }
    if (toBase == 10) {
        printf("Result number: %s (base%d) = %llu (base10)\n", strIn, fromBase, base10);
        return 0;
    }
    fromDec(strOut, toBase, base10);
    if (fromBase == 10)
        printf("Result number: %llu (base10) = %s (base%d)\n", base10, strOut, toBase);
    else
        printf("Result number: %s (base%d) = %llu (base10) = %s (base%d)\n", strIn, fromBase, base10, strOut, toBase);

    return 0;
}