#include <stdio.h>
#include <string.h>

char pass[] = "1234";

int main(void){
    char str[100];
    printf("Enter password: ");
    scanf("%s", str);
    if (!strncmp(str, pass, 100)){
        printf ("Hello to our system!\n");
    } else {
        printf("Incorrect password!\n");
    }
    return 0;
}