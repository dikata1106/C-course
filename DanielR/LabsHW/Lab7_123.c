#include <stdio.h>

// Ex.1
int myStrlen(const char *str) {
    int cnt = 0;
    // assert str != NULL
    while (str[cnt] != '\0') {
        cnt++;
    }
    return cnt;
}

//Ex.2
void myStrcat(const char *str1, const char *str2, char* destination) {
    int i = 0, j = 0;
    // assert str1 != NULL && str2 != NULL 
    while (str1[i] != '\0') {
        destination[i] = str1[i];
        i++;
    }
    while (str2[j] != '\0') {
        destination[i] = str2[j];
        i++;
        j++;
    }
    destination[i] = '\0';
    return;
}

// Ex.3
void printArr(unsigned short* arr, int n) {
    int i;
    printf("Length=%d, elements=[ ", n);
    for(i=0; i<n; i++)
        printf("%hd ", *(arr+i));
    printf("]\n");
    return;
}

void inputArr(unsigned short* arr, int n) {
    printf("Insert %d unsigned shorts into array:\n", n);
    int i;
    for(i=0; i<n; i++)
        scanf("%hd", (arr+i));
    return;
}

void mySort(unsigned short* arr, int n) {
    int nOfOccurances[(1<<16)-1] = {0, }, sortedCount = 0, i, j;
    for (i=0; i<n; i++) {
        nOfOccurances[arr[i]]++;
    }
    // for (i=((1<<16)-2); i>=0; i--) {  // reverse
    for (i=0; i<((1<<16)-1); i++) {
        for (j=0; j<nOfOccurances[i]; j++) {
            arr[sortedCount++] = i;
        }
    }
}

int main(void) {
    printf("%d\n", myStrlen("hello"));  //str defined as const char
    char d[100];
    myStrcat("hello ", "world", d);
    printf("%s\n", d);
    unsigned short s[10];
    inputArr(s, 10);
    mySort(s, 10);
    printArr(s, 10);
}