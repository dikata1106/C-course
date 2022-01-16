#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE !0
//Ex.1
// return 0 if different signs, !0 if same signs
int same_signs(int a, int b) {
    return ((a^b) >= 0);
    // return (a^b)<0; // 1 if different signd, 0 if different
}

// Ex.2
// return 7*n
int multiply_by_7(int n) {
    return ((n<<3) - n);
}

// Ex.3
// return number of bits in binary representation of n
int number_of_bits(int n) {
    int cnt = 0;
    if (n==0)
        return (1);
    while (n != 0) {
        n>>=1;
        cnt++;
    }
    // int cnt = 1;
    // while (n>>=1)    // error with 0,  goes negative
    //     cnt++;
    return (cnt);
}
// Same with only 1 call using log base 2
int number_of_bits_log2(int n) {
    return (((int) log2(n)) + 1);
}

// Ex.4
int get_Bit(int n, int bitI) {
    // return (!!(n & (1<<bitI)));
    return ((n>>bitI)&1);
}

int get_Reverse(int n) {
    int i, res = 0, allBitCount = 0;
    allBitCount = number_of_bits_log2(n);
    for (i=0; i<allBitCount; i++) {
        // printf("%d += %d << %d --> ", res, get_Bit(n, i), (allBitCount-i));
        res += get_Bit(n, i)<<(allBitCount-i-1);
        // printf("res = %d\n", res);
    }
    return (res);
}

int is_Palindrom(int n) {
    if (n == 0)
        return TRUE;
    else
        return (n == get_Reverse(n));
}

int palindroms(int nBits) {
    int i, cnt = 0;
    if (nBits == 0)
        return (0);
    // if include 0 value with 1 bit representation, does not include values like 00, 000, 0000, ...
    // if (nBits == 1)
    //     return (2);
    for (i=(1<<(nBits-1)); i<(1<<nBits); i++) {
        if (is_Palindrom(i)) {
            // printf("%d ", i);
            cnt++;
        }
    }
    // putchar('\n');
    return (cnt);
}

// Ex.5
char symbol_change(char c) {
    return ((c<='9' && c>='0') ? (c + 17) : ((c<='Z' && c>='A') ? (c | ' ') : ('\'')));
}

int main(void) {
    int n;
    char c[16] = {'A', 'B', 'C', '/','X', 'Y', 'Z', 'a', '_', 'z', '0', '1', '8', '9', '$', '\''};
    // printf("N = %d, rev(N) = %d\n", n, get_Reverse(n));
    // printf("Is palindrom value %d\n", is_Palindrom(n));
    for(n=0; n<16; n++)
        printf("%d palindroms found with %d bits\n", palindroms(n), n);
    printf("A B C / X Y Z a _ z 0 1 8 9 $ \\ \n");
    for(n=0; n<16; n++)
        printf("%c ", symbol_change(c[n]));
    putchar('\n');
    return 0;
}