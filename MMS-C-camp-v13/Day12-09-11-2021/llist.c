#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct {
    char title[100];
    char autor[100];
    int pages;
    double price;
} book_t;

typedef struct nodeb {
    book_t data;
    struct nodeb *next;
} bookNode_t;

typedef struct nodeu {
    void* data;
    struct nodeu *next;
} uninode_t;

void push(node_t **list, int value){
    node_t* n = malloc(sizeof(node_t));
    n->data = value;
    n->next = *list;
    *list = n;
}

void printList(node_t *list){
    node_t* current = list;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

int sumList(node_t *list){
    int sum = 0;
    node_t* current = list;
    while (current != NULL){
        sum += current->data;
        current = current->next;
    }
    return sum;
}

void pop(node_t **list){
    if (*list == NULL){
        return;
    }
    node_t* temp = *list;
    *list = (*list)->next;
    free(temp);
}

void freeList(node_t **list){
    node_t* current = *list;
    node_t* temp = current;
    while (current != NULL){
        temp = current;
        current = current->next;
        free(temp);
    }
    *list = NULL;
}

void printListR(node_t* list){
    if (list == NULL){
        return;
    }
    printListR(list->next);
    printf("%d ", list->data);
}

int main(){
    node_t* myList = NULL;
    pop(&myList);
    push(&myList, 10);
    push(&myList, 20);
    push(&myList, 45);
    push(&myList, 43);
    if (myList == NULL){
        printf("List is empty!\n");
        exit(EXIT_FAILURE);
    }
    printListR(myList);
   // printf("Sum = %d\n", sumList(myList));
    
    freeList(&myList);
    return EXIT_SUCCESS;
}