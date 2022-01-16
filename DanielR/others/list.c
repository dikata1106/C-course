#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void push(node_t **list, int value) {
    node_t *n = (node_t *)malloc(sizeof(node_t));
    n->data = value;
    n->next = *list;
    *list = n;
}

void pop(node_t **list) {
    if (*list == NULL) {
        return;
    }
    node_t *n = *list;
    *list = (*list)->next;
    free(n);
}

void printList(node_t *list) {
    while(list != NULL) {
        printf("%d ", list->data);
        list = list->next;
    }
    putchar('\n');
}

void freeList(node_t **list) {
    node_t *n;
    while (*list != NULL) {
        n = *list;
        *list = (*list)->next;
        free(n);
    }
}

int sumList(node_t *list) {
    int sum = 0;
    while(list != NULL) {
        sum += list->data;
        list = list->next;
    }
    return sum;
}

int main(void) {

    // node_t n1, n2;
    // n1.data = 10;
    // n1.next = &n2;
    // n2.next = 20;
    // n2.next = NULL;

    node_t *myList = NULL;
    push(&myList, 10);
    push(&myList, 20);
    push(&myList, 45);
    push(&myList, 43);
    printList(myList);
    printf("%d\n", sumList(myList));
    pop(&myList);
    printList(myList);
    freeList(&myList);
    printList(myList);
    return EXIT_SUCCESS;
}