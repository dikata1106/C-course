#include <stdio.h>
#include <limits.h>

#define SIZE(array) (sizeof(array)/sizeof(*array))

int maxElement(int* arr, int n) {
    int i, max = *arr;
    for (i=1; i<n; i++)
        if (arr[i] > max)
            max = arr[i];
    return(max);	// assert arr != NULL and arr = int*
}

int minElement(int* arr, int n) {
	int i, min = *arr;
	for (i=1; i<n; i++)
		if (arr[i] < min)
			min = arr[i];
		// min = (arr[i] < min) ? (arr[i]) : (min);
	return(min);	// assert arr != NULL and arr = int*
}

int minElementIndex(int* arr, int n) {
	int i, min = *arr;
	for (i=1; i<n; i++)
		if (arr[i] < min)
			min = arr[i];
		// min = (arr[i] < min) ? (arr[i]) : (min);
	return(min);	// assert arr != NULL and arr = int*
}

double average(int* arr, int n) {
	int sum = 0, i;
	for (i=0; i<n; i++)
		sum += arr[i];
	return (double)sum / n;
}

int main(void) {
	printf("HI\n");
	return 0;
}