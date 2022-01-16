#include <stdio.h>
#include <stdlib.h>

unsigned char CheckBit(unsigned int);
void Reverse(char *);
void VMirror(unsigned char *);
void Conv(int, char *);
#define MAX_SIZE 4
typedef struct {
    int arr[ MAX_SIZE ];
    int top;
    int bottom;
} ring_buffer;
int IsEmpty(ring_buffer *);
int IsFull(ring_buffer *);
void Push(ring_buffer *, int);
int Pop(ring_buffer *);
void swap(int *, int *);
void Bubble(int *, unsigned int);
unsigned int BinSearch(unsigned int *, unsigned int, unsigned int);
void Add(const char *, const char *, char *);

int main(void) {

    int i, j;

    // // Ex.1
    // printf("Ex.1\n");
    // printf("0x0400 -> %x\n", CheckBit(0x0400));
    // printf("0x0600 -> %x\n", CheckBit(0x0600));
    // printf("0x0000 -> %x\n", CheckBit(0x0000));
    // putchar('\n');

    // // Ex.2
    // printf("Ex.2\n");
    // char str[] = "This is a test";
    // Reverse(str);
    // printf("%s\n", str);
    // putchar('\n');

    // // Ex.3
    // printf("Ex.3\n");
    // unsigned char img[] = {0x7F,0x40,0x40,0x40,0x7F,0x00,0x00,0x00};
    // VMirror(img);
    // for (i=0; i<8; i++)
    //     printf("%X ", img[i]);
    // putchar('\n');
    // putchar('\n');

    // // Ex.4
    // printf("Ex.4\n");
    // char num[10];
    // Conv(-26, num);
    // printf("%s\n", num);
    // Conv(16025, num);
    // printf("%s\n", num);
    // putchar('\n');

    // Ex.5
    printf("Ex.5\n");
    ring_buffer rb;
    rb.top = -1;
    rb.bottom = 0;
    printf("Ring Buffer size: %d\n", MAX_SIZE);
    printf("Initially IsEmpty value: %d (top=%d, bottom=%d)\n", IsEmpty(&rb), rb.top, rb.bottom);
    printf("Initially IsFull value: %d (top=%d, bottom=%d)\n", IsFull(&rb), rb.top, rb.bottom);
    printf("Push 5\n"); Push(&rb, 5);
    printf("IsEmpty value: %d (top=%d, bottom=%d)\n", IsEmpty(&rb), rb.top, rb.bottom);
    printf("IsFull value: %d (top=%d, bottom=%d)\n", IsFull(&rb), rb.top, rb.bottom);
    printf("Push 7 8 9\n"); Push(&rb, 7); Push(&rb, 8); Push(&rb, 9);
    printf("IsEmpty value: %d (top=%d, bottom=%d)\n", IsEmpty(&rb), rb.top, rb.bottom);
    printf("IsFull value: %d (top=%d, bottom=%d)\n", IsFull(&rb), rb.top, rb.bottom);
    printf("Pop %d\n", Pop(&rb));
    printf("IsEmpty value: %d (top=%d, bottom=%d)\n", IsEmpty(&rb), rb.top, rb.bottom);
    printf("IsFull value: %d (top=%d, bottom=%d)\n", IsFull(&rb), rb.top, rb.bottom);
    printf("Push 3\n"); Push(&rb, 3);
    printf("IsEmpty value: %d (top=%d, bottom=%d)\n", IsEmpty(&rb), rb.top, rb.bottom);
    printf("IsFull value: %d (top=%d, bottom=%d)\n", IsFull(&rb), rb.top, rb.bottom);
    putchar('\n');

    // // Ex.6
    // printf("Ex.6\n");
    // int arr[] = {64, 34, 25, 12, 22, 11, 90};
    // int n = sizeof(arr)/sizeof(arr[0]);
    // Bubble(arr, n);
    // for (i=0; i<n; i++)
    //     printf("%d ", arr[i]);
    // putchar('\n');
    // putchar('\n');

    // // Ex.7
    // printf("Ex.7\n");
    // unsigned int uarr[] = {};
    // printf("%d\n", BinSearch(arr, n, 25));
    // printf("%d\n", BinSearch(arr, n, 15));
    // printf("%d\n", BinSearch(arr, 0, 15));
    // putchar('\n');

    // // Ex.8
    // printf("Ex.8\n");
    // char sum[10]; 
    // Add("11111", "222", sum);
    // printf("%s", sum);
    // putchar('\n');


    return EXIT_SUCCESS;
}

// Ex.1
unsigned char CheckBit(unsigned int uValue) {
    int i = 0, end = sizeof(unsigned int)*8;
    if (uValue == 0x0000) {
        return 0x00;
    }
    while (i < end) {
        if ((uValue & (1<<i)) == uValue) {
            return 0x01;
        } else {
            i++;
        }
    }
    return 0x00;
}

// Ex.2
void Reverse(char* ptr) {
    int len = 0, i = 0;
    char c;
    if (ptr == NULL) {
        return;
    }
    while (ptr[len] != '\0') {
        len++;
    }
    // printf("%d ", len);
    while(i != (len/2)) {
        ptr[i] ^= ptr[len-i-1];
        ptr[len-i-1] ^= ptr[i];
        ptr[i] ^= ptr[len-i-1];
        i++;
    }
    return;
}

// Ex.3
void VMirror(unsigned char *pImage) {
    int i, j;
    unsigned char c;
    for (i=0; i<8; i++) {
        c = 0x00;
        for (j=0; j<8; j++) {
            if (pImage[i] & (1<<j)) {
                c |= (1<<(7-j));
            }
        }
        pImage[i] = c;
    }
}

// Ex.4
void Conv(int sValue, char *pBuffer) {
    // signed 16 bit number (int)
    // INT16_MIN to INT16_MAX , which is [−32768, +32767].
    if(!(-32768 <= sValue &&  32767 >= sValue)) {
        return;
    }
    if (sValue & (1<<(sizeof(sValue)*8-1))) {
        pBuffer[0] = '-';
        sValue *= -1;
    } else {
        pBuffer[0] = ' ';
    }
    int i = 6, mod;
    pBuffer[i--] = '\0';
    while (sValue) {
        mod = sValue % 10;
        sValue /= 10;
        switch (mod) {
        case 0:
            pBuffer[i] = '0';
            break;
        case 1:
            pBuffer[i] = '1';
            break;
        case 2:
            pBuffer[i] = '2';
            break;
        case 3:
            pBuffer[i] = '3';
            break;
        case 4:
            pBuffer[i] = '4';
            break;
        case 5:
            pBuffer[i] = '5';
            break;
        case 6:
            pBuffer[i] = '6';
            break;
        case 7:
            pBuffer[i] = '7';
            break;
        case 8:
            pBuffer[i] = '8';
            break;
        case 9:
            pBuffer[i] = '9';
            break;
        default:
            break;
        }
        i--;
    }
    while (i > 0) {
        pBuffer[i--] = ' ';
    }
}

// Ex.5
int IsEmpty(ring_buffer *rb) {
    // printf("IsEmpty: rb->bottom %d, rb->top %d\n", rb->bottom, rb->top);
    return (rb->top - rb->bottom) != 0; // !(rb->top == rb->bottom);
}
int IsFull(ring_buffer *rb) {
    // printf("IsFull: rb->bottom %d, rb->top %d\n", rb->bottom, rb->top);
    return ((rb->top == rb->bottom-1) || (rb->top==MAX_SIZE-1 && rb->bottom==0));
}
void Push(ring_buffer *rb, int nNewValue) {
    // assert IsFull != 0
    // printf("rb->top before push %d\n", rb->top);
    if (++(rb->top) == MAX_SIZE)
        rb->top = 0;
    rb->arr[rb->top] = nNewValue;
    // printf("rb->top after push %d\n", rb->top);
    return;
}
int Pop(ring_buffer *rb) {
    // assert IsFull != 0
    // printf("rb->bottom before pop %d\n", rb->bottom);
    int value = rb->arr[rb->bottom];
    if (++(rb->bottom) == MAX_SIZE)
        rb->bottom = 0;
    // printf("rb->bottom after pop %d\n", rb->bottom);
    return value;
}

// Ex.6
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void Bubble(int *pArray, unsigned int uLen) {
    int i, j;
    for (i = 0; i < uLen-1; i++)     
        for (j = 0; j < uLen-i-1; j++)
            if (pArray[j] > pArray[j+1])
                swap(&pArray[j], &pArray[j+1]);
}

// Ex.7
unsigned int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return 0xFFFF;
}
unsigned int BinSearch(unsigned int *pArray, unsigned int uArraySize, unsigned int uValue) {
    return binarySearch(pArray, 0, uArraySize, uValue);
}

// Ex.8
void Add(const char* p1, const char* p2, char* result) {
    // int len1 = 0, len2 = 0, len = 1, sum = 0;
    // while (p1[len1] != '\0') {
    //     len1++;
    // }
    // while (p2[len2] != '\0') {
    //     len2++;
    // }
    // len += (len1 > len2) ? len1 : len2;
    // printf("%d ", len);
    // result[len--] = '\0';
    // while (len > 0) {
    //     printf("%d ", len);
    //     result[len] = '0';
    //     //result[len] = p1[len] + p2[len];
    //     len--;
    // }
    // printf("%d ", len);
    // result[len] = (sum == '0') ? ' ' : sum;
}