#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#define LEN(arr) (sizeof(arr)/sizeof(*arr))

int compareInt1(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}

int compareDouble(const void* a, const void* b){
    double num1 = *(double*)a;
    double num2 = *(double*)b;
    if (num1 < num2){
        return 1;
    } else if (num1 > num2){
        return -1;
    }
    return 0;
}


void printArray(double* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("%lf ", *(arr+i));
    }
    putchar('\n');
}


void swap(int* a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapUni(void* a, void *b, size_t size){
    uint8_t temp[size];
    memmove(temp, a, size);
    memmove(a, b, size);
    memmove(b, temp, size);
}

int compareInt2(int a, int b){
    return b - a;
}

void bubbleSort(void* arr, size_t nmemb, size_t size, int (*cmp)(const void*,const void*)){
    for (int j = 0; j < nmemb; j++){
        int swapped = 0;
        for (int i = 0; i < (nmemb - j - 1) * size; i += size){
            if (cmp(arr + i, arr + i + size) > 0){
                swapUni(arr + i, arr + i + size, size);
                swapped = 1;
            }
        }
        if (!swapped){
            return; // sorted break
        }
    }
} // broi 1 ->>>>>   0b1000000, 0b0000011, 0x0f, 0xaf, 0xffff.......



void* linearSearch(const void* key, void* arr, size_t nitems, size_t size, int (*cmp)(const void* a, const void* b)){
    for (int i = 0; i < nitems * size; i += size){
        if (cmp(arr + i, key) == 0){
            return arr + i;
        }
    }
    return NULL;
}

typedef struct {
    char marka[100];
    int maxspeed;
    double price;
} car;

typedef struct {
    double x;
    double y;
} point;

double distance(point p1, point p2){
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double mhdistance(point p1, point p2){
    return fabs(p1.x - p2.x) + fabs(p1.y - p2.y); 
}

point translate(point p, double x, double y){
    point result;
    result.x = p.x + x;
    result.y = p.y + y;
    return result;
}

void printCars(car* arr, size_t n){
    for (int i = 0; i < n; i++){
        printf("Marka: %s, Max speed: %d, Price %.2lf\n", arr[i].marka, arr[i].maxspeed, arr[i].price);
    }
}

int compareCar(const void* a, const void* b){
    car* car1 = (car*)a;
    car* car2 = (car*)b;
    return strcmp(car2->marka, car1->marka);
}

void quickSort(int* arr, int size){
    if (size > 1){
        int pivot = arr[rand() % size];

        int left = 0;
        for (int i = 0; i < size; i++){
            if (arr[i] < pivot){
                swap(&arr[i], &arr[left++]);
            }
        }
        quickSort(arr, left);

        int right = size - 1;
        for (int i = size - 1; i >= left; i--){
            if (arr[i] > pivot){
                swap(&arr[i], &arr[right--]);
            }
        }
        quickSort(arr + right + 1, size - right - 1);
    }
}

int main(void){
    /*car cars[] = { {"Opel", 200, 2000.00}, 
                   {"Honda", 230, 5040.20},
                    {"Moskvich", 350, 230.30},
                    {"Ford", 345, 3450.34},
                    {"Trabant", 120, 100} };
    bubbleSort(cars, LEN(cars), sizeof(car), compareCar);
    printCars(cars, LEN(cars));*/
    int arr[] = {10, 20, 34, 5, 55, 332, 43 };
    quickSort(arr, LEN(arr));
    for (int i = 0; i < LEN(arr); i++){
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}