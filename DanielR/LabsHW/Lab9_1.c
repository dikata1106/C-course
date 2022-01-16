#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createConcat(const char *str1, const char *str2) {
    char *result = malloc((strlen(str1) + strlen(str2))*sizeof(char));
    strcpy(result, str1);
    strcpy(result + strlen(result), str2);
    return result;
}

int main(void) {
    char *str = createConcat("Hello", "World");
    printf("%s\n", str);
    return 0;
}