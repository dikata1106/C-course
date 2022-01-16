#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define LEN(arr) (sizeof(arr)/sizeof(arr[0])) 

int main(void){
    int arr[20];
    float arrf[1024];
    int a = 0;
    char *str = "Hello";
    printf("Max int: %u\n", (unsigned)(-1));
    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Size of short: %lu bytes\n", sizeof(short));
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of long: %lu bytes\n", sizeof(long));
    printf("Size of long long: %lu bytes\n", sizeof(long long));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of void int8_t: %lu bytes\n", sizeof(int8_t));
    printf("Size of void uint8_t: %lu bytes\n", sizeof(uint8_t));
    printf("Size of void int16_t: %lu bytes\n", sizeof(int16_t));
    printf("Size of void int32_t: %lu bytes\n", sizeof(int32_t));
    printf("Size of void int64_t: %lu bytes\n", sizeof(int64_t));
    printf("Size of char ptr: %lu bytes\n", sizeof(char*));
    printf("Size of int ptr: %lu bytes\n", sizeof(int*));
    printf("Size of double ptr: %lu bytes\n", sizeof(double*));
    printf("Size of void ptr: %lu bytes\n", sizeof(void*));
    printf("Size of a: %lu bytes\n", sizeof(a));
    printf("Size of a: %lu bytes\n", sizeof(arr));
    printf("Number of elements (arr): %lu\n", LEN(arr));
    printf("Number of elements (arrf): %lu\n", LEN(arrf));
    printf("Number of elements (str): %lu\n", strlen(str));
    return 0;
}