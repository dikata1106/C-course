#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* pushFront(struct Node* arr, int newElem) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        fprintf(stderr, "Could not allocate\n");
        return arr;
    }
    newNode->data = newElem;
    newNode->next = arr;
    return newNode;
}

struct Node* popFront(struct Node* arr) {
    if (!arr->next) {
        free(arr);
        return NULL;
    }
    struct Node *deleted = arr;
    arr = arr->next;
    free(deleted);
    return arr;
}

struct Node* reverse(struct Node *arr) {
    struct Node* res = NULL;
    while(arr) {
        res = pushFront(arr->data, res);
        arr = popFront(arr);
    }
    return res;
}
struct Node* pushBack(struct Node* arr, int newElem);
struct Node* getNode(struct Node* arr, int index);

struct Node* popBack(struct Node* arr) {
    struct Node *lastNode, *newLastNode, *cur = arr;
    if(!arr) {
        fprintf(stderr, "Empty list\n");
        return arr;
    }
    if (!arr->next) {
        free(arr);
        return NULL;
    }
    while(cur->next->next) {
        cur = cur->next;
    }
    newLastNode = cur;
    lastNode = cur->next;
    newLastNode->next = NULL;
    free(lastNode);
    return arr;
}

void print(struct Node* arr) {
    
    while(arr) {
        printf("%d ", arr->data);
        arr = arr->next;
    }
}

int main(void) {
    return 0;
}