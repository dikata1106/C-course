#include <stdio.h>

int main(void){
    char firstname[10], lastname[10];
    scanf("%s %s", firstname, lastname);
    // fgets(str, 10, stdin);  // file get string
    printf("Firstname = %s , Lastname = %s\n", firstname, lastname);
    return 0;
}
