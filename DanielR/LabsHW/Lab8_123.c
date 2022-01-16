#include <stdio.h>

#define SIZE(a) (sizeof(a)/sizeof(*a))

int getWoodForCut(int* heights, int n, int k) {
    int i, sumWood = 0;
    for (i=0; i<n; i++) {
        if (heights[i] > k) {
            sumWood += (heights[i] - k);
        }
    }
    return sumWood;
}

void merge(int *dest, const int *arr1, int N1, const int *arr2, int N2) {
    int i = 0, j = 0, k = 0;
    while (i<N1 && j<N2) {
        if(arr1[i] <= arr2[j]) {
            dest[k] = arr1[i];
            i++;
        } else {
            dest[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i<N1) {
        dest[k] = arr1[i];
        i++;
        k++;
    }
    while (j<N2) {
        dest[k] = arr2[j];
        j++;
        k++;
    }
    return;
}

void printIntArr(int* a, int n) {
    int i;
    printf("[ ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("] ");
    return;
}

int countPaths(int n, int m) {

    if (n==0 || m==0)
        return 1;
    return (countPaths(n-1, m) + countPaths(n, m-1));
}

int main(void) {

    // EX.1
    // int i, j, n, heights[1000000], b, maxHeight = -1, curWood = 0;
    // scanf("%d", &n);
    // for (i=0; i<n; i++) {
    //     scanf("%d", &heights[i]);
    //     if (maxHeight < heights[i]) {
    //         maxHeight = heights[i];
    //     }
    // }
    // scanf("%d", &b);

    // EX.1A
    // for (j=maxHeight; j>0 && curWood<b; j--) {
    //     curWood = getWoodForCut(heights, n, j);
    // }
    // printf("%d\n", j+1);

    // EX.1B
    // int lo = 0, hi = maxHeight, mid;
    // while (lo <= hi) {
    //     mid = (lo+hi)/2;
    //     curWood = getWoodForCut(heights, n, mid);
    //     if (curWood == b) {
    //         lo =  hi+1; // break;
    //         printf("%d\n", mid);
    //     } else if (curWood > b) {
    //         hi = mid + 1;
    //     } else {
    //         hi = mid - 1;
    //     }
    // }

    // EX.2
    int a[10], b[] = {1, 4, 5}, c[] = {0, 2, 5, 9};
    printIntArr(b, SIZE(b));
    printf("+ ");
    printIntArr(c, SIZE(c));
    printf("--> merge --> ");
    merge(a, b, SIZE(b), c, SIZE(c));
    printIntArr(c, (SIZE(b)+SIZE(c)));
    putchar('\n');

    // EX.3
    // int n = 3, m = 2;
    // printf("\nCount paths from (%d, %d) to (0, 0) = %d\n", n, m, countPaths(n, m));
    
    return 0;
}