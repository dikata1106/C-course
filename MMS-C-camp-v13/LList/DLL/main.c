#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
} node_t;

void push(node_t** dlist, int data){
    node_t* n = (node_t*)malloc(sizeof(node_t));
    n->data = data;
    n->prev = NULL;
    n->next = *dlist;
    if (*dlist != NULL){
        (*dlist)->prev = n;
    }
    *dlist = n;
}

void print_list(node_t* dlist){
    node_t* current = dlist;
    while (current != NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

void append(node_t** dlist, int data){
    if (*dlist == NULL){
        push(dlist, data);
        return;
    }
    node_t* n = (node_t*)malloc(sizeof(node_t));
    n->data = data;
    n->next = NULL;
    node_t* current = *dlist;
    while (current->next != NULL){
        current = current->next;
    }
    current->next = n;
    n->prev = current;
}

void insertNth(node_t** dlist, int data, size_t n){
    if (n == 0 || *dlist == NULL){
        push(dlist, data);
        return;
    }
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->prev = node->next = NULL;
    node_t* current = *dlist;
    while (n-- && current->next != NULL){
        current = current->next;
    }
    current->prev->next = node;
    node->prev = current->prev;
    node->next = current;
    current->prev = node;
}

int main(void){
    node_t* dlist = NULL;
    insertNth(&dlist, 10, 0);
    insertNth(&dlist, 20, 0);
    insertNth(&dlist, 30, 1);
    insertNth(&dlist, 40, 0);
    insertNth(&dlist, 50, 0);
    print_list(dlist);
    return 0;

}