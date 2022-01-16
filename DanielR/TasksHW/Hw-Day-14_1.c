#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

typedef struct {
    char title[150];
    char autor[100];
    int pages;
    double price;
} book;

typedef struct node {
    book data;
    struct node* next;
} node_t;

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void printBooks(node_t* list){
    node_t* current = list;
    int i;
    for ( i = 0; i<COUNT; i++){
        printf("Title: %20s, Autor: %20s, Pages: %d,\tPrice: %.2lf\n", current->data.title, current->data.autor, current->data.pages, current->data.price);
        current = current->next;
    }
    // while (current != NULL){
    //     printf("Title: %20s, Autor: %20s, Pages: %d,\tPrice: %.2lf\n", current->data.title, current->data.autor, current->data.pages, current->data.price);
    //     current = current->next;
    //     printf("N\n");
    // }
    // printf("NNNN\n");
    putchar('\n');
}

void print_listR(node_t* list){
    if (list == NULL){
        return;
    }
    printf("Title: %20s, Autor: %20s, Pages: %d,\tPrice: %.2lf\n", list->data.title, list->data.autor, list->data.pages, list->data.price);
    print_listR(list->next);
}

void print_listRRev(node_t* list){
    if (list == NULL){
        return;
    }
    print_listRRev(list->next);
    printf("Title: %20s, Autor: %20s, Pages: %d,\tPrice: %.2lf\n", list->data.title, list->data.autor, list->data.pages, list->data.price);
}

node_t* create_node(book data){
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    for (int i = 0; i<COUNT; i++){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

// merge sort
int compareTitle(const void* a, const void* b) {
    return strcmp((*((book*)a)).title, ((book*)b)->title);
}

node_t* sortedMerge(node_t* listA, node_t* listB, int(*cmp)(const void*, const void*)){
    node_t* sorted = NULL;
    if (listA == NULL){
        return listB;
    }
    if (listB == NULL){
        return listA;
    }
    if (cmp(&(listA->data.title), &(listB->data.title)) > 0){
        sorted = listA;
        sorted->next = sortedMerge(listA->next, listB, cmp);
    } else {
        sorted = listB;
        sorted->next = sortedMerge(listA, listB->next, cmp);
    }
    return sorted;
}


void frontBackSplit(node_t* list, node_t** front, node_t** back){
    node_t* slow = list;
    node_t* fast = list->next;
    while (fast != NULL){
        fast = fast->next;
        if (fast  != NULL){
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = list;
    *back = slow->next;
    slow->next = NULL;
}

void mergeSort(node_t** list, int(*cmp)(const void*, const void*)){
    if (*list == NULL || (*list)->next == NULL){
        return;
    }
    node_t *front = NULL, *back = NULL;
    frontBackSplit(*list, &front, &back);
    mergeSort(&front, cmp);
    mergeSort(&back, cmp);
    *list = sortedMerge(front, back, cmp);
}


int main(void) {
    srand(time(NULL));
    int i, j, chars;
    book b;
    node_t *myBooksList, *aux;
    for (i=0; i<COUNT; i++) {
        // printf("book %d ", i);
        b.pages = randomInt(5, 2000);
        b.price = randomReal(1.0, 1000.0);
        chars = randomInt(10, 20);
        b.title[0] = randomInt('A', 'Z');
        for(j=1; j<chars; j++) {
            b.title[j] = randomInt('a', 'z');
        }
        b.title[j] = '\0';
        chars = randomInt(10, 20);
        b.autor[0] = randomInt('A', 'Z');
        for(j=1; j<chars; j++) {
            b.autor[j] = randomInt('a', 'z');
        }
        b.autor[j] = '\0';
        aux = create_node(b);
        aux->next = myBooksList;
        myBooksList = aux;
    }

    mergeSort(&myBooksList, compareTitle);
    printBooks(myBooksList);
    listFree(&myBooksList);

 
    // bubbleSort(books, COUNT, sizeof(book), compareTitle);

    // books[5].price = 20.5;
    // // strcpy(books[5].title, "Jurassic Park");
    // book tmp = {"Jurassic Park", "Key book for search", 538, 20.5};
    // book* searched = linearSearch((void*)&tmp, books, COUNT, sizeof(book), comparePrice);
    // if(searched != NULL) {
    //     printf("Book title with price 20.5 is %s\n", searched->title);
    // } else {
    //     printf("No book with price 20.5 was found\n");
    // }
    // printBooks(books, COUNT);


    return 0;
}