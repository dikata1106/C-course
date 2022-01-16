// Daniel Ruskov Vangelov 27/10/2021
#include <stdio.h>
#include <stdint.h>

int checkBit(uint64_t mask, int bit){
    return (mask & (1 << bit)) ? 1 : 0;
}

void printBits(uint64_t mask){
    for (int i = sizeof(uint64_t)*8 - 1; i >= 0; i--){
        printf("%d", checkBit(mask, i));
        if(i%4 == 0)
            printf(" ");
    }
    putchar('\n');
}

uint64_t setBit(uint64_t mask, int bit){
    printBits(mask);
    printBits((uint64_t)1<<bit);
    printBits(mask | (1 << bit));
    return mask | ((uint64_t)1 << bit);
}


uint64_t clearBit(uint64_t mask, int bit){
    printBits(mask);
    printBits(~(1 << bit));
    printBits(mask & ~(1 << bit));
    return mask & ~(1 << bit);
}

uint64_t invertBit(uint64_t mask, int bit){
    printBits(mask);
    printBits(1<<bit);
    printBits(mask ^ (1 << bit));
    return mask ^ (1 << bit);
}

void present(uint64_t mask){
    printf("Present: ");
    int a = sizeof(uint64_t)*8;
    for (int i = 0; i < a; i++){
        if (checkBit(mask, i))
            printf("%d ", i);
    }
    putchar('\n');
}

void absent(uint64_t mask){
    printf("Absent: ");
    int a = sizeof(uint64_t)*8;
    for (int i = 0; i < a; i++){
        if (!checkBit(mask, i))
            printf("%d ", i);
    }
    putchar('\n');
}

int checkStudent(int student) {
    return student >= 0 && student < 64;
}

int main(void) {
    /*
    unsigned long long a = 3;
    uint64_t n=3, sh = 2;
    printBits(0x0123456789abcdef);
    printBits(0xffffffffffffffff<<sh);
    */
   printf("ATTENTION! This program crashes when using uint64_t and shift bits. It has been found that with uint8_t, uint16_t and uint32_t it works fine. Compilation with gcc and clang has also been tested, but the result is the same.\n");
    uint64_t attendance = 0ll;
    int option, student;

    while (1) {
        printf("=======================\n");
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Present students\n");
        printf("6. Absent students\n");
        printf("7. Exit\n");
        printf("-----------------------\n");
        scanf("%d", &option);
        if (option == 1) {
            printf("Whose attendance?\n");
            scanf("%d", &student);
            if(checkStudent(student))
                attendance = setBit(attendance, student);
            else
                printf("%d student out of range (0..63)\n", student);
        } else if (option == 2) {
            printf("Whose attendance?\n");
            scanf("%d", &student);
            if(checkStudent(student))
                attendance = clearBit(attendance, student);
            else
                printf("%d student out of range (0..63)\n", student);
        } else if (option == 3) {
            printf("Attendance: ");
           printBits(attendance);
        } else if (option == 4) {
            printf("Whose attendance?\n");
            scanf("%d", &student);
            if(checkStudent(student))
                attendance = invertBit(attendance, student);
            else
                printf("%d student out of range (0..63)\n", student);
        } else if (option == 5) {
           present(attendance);
        } else if (option == 6) {
           absent(attendance);
        } else if (option == 7) {
            printf("Good bye!\n");
            break;
        } else {
            printf("Wrong option, please select a valid option.\n");
        }
        putchar('\n');
    }
    return 0;
}