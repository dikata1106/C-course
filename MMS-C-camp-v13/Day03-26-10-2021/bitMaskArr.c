#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

#define SIZE 3

uint16_t bitmask[SIZE];

void setBit(unsigned bit, size_t typeB){
    typeB *= CHAR_BIT;
    bitmask[bit / typeB] |= (1 << (bit % typeB));
}

void clearBit(unsigned bit, size_t typeB){
    typeB *= CHAR_BIT;
    bitmask[bit / typeB] &= ~(1 << bit % typeB);
}

int checkBit(unsigned bit, size_t typeB){
    typeB *= CHAR_BIT;
    return (bitmask[bit / typeB] & (1 << bit % typeB)) ? 1 : 0;
}

void printBits(size_t typeB){
    for (int i = SIZE - 1; i >= 0; i--){
        for (int j = typeB*8 - 1; j >= 0; j--){
            printf("%d", checkBit(j, typeB));
        }
    }
    putchar('\n');
}

void arrc(int *a){
    for (int i = 0; i < 10; i++){
        a[i] = i*10;
    }
}
typedef struct node {
    int val;
    struct node *next;
} node_t;

void ll(node_t **head, int el){
    node_t* n = malloc(sizeof(node_t));
    n->val = el;
    n->next = *head;
    *head = n;
}

void addEnd(node_t **head, int el){
    node_t* n = malloc(sizeof(node_t));
    n->next = NULL;
    n->val = el;
    node_t* current = *head;
    if (*head != NULL)
    {while(current->next) {printf("%d ", current->val); current = current->next;}
    current->next = n;}
    *head = n;
}

void print(node_t *head){
    node_t* current = head;
    while(current) {printf("%d ", current->val); current = current->next;}
    printf("\n");
}
int main(){
    node_t* head = NULL;
    //ll(&head, 10);
    //ll(&head, 20);
    ll(&head, 5);
    addEnd(&head, 100);
    print(head);
    return 0;
}