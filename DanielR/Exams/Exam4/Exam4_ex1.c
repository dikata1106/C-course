#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


typedef struct {
    double weight;
    double price;
    uint16_t number;
    char description[250];
} item_t;

typedef struct node {
    item_t data;
    struct node* next;
} node_t;

#define ITEMS_COUNT 3

int randomInt(int min, int max) {
    return min + rand() % (max-min+1);
}

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

void print_list(node_t* list){
    node_t* current = list;
    while (current != NULL){
        printf("\nNumber: %hd\nDescription: %s\nWeight: %.4lf\nPrice: %.4lf\n", current->data.number, current->data.description, current->data.weight, current->data.price);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    while (current){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void push(node_t** list, item_t data){
    node_t* n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

node_t* removeItem(node_t** items, uint16_t number){
    if (*items == NULL){
        return NULL;
    }
    node_t* current = *items;
    node_t* prev = current;
    while (current && (current->data.number != number)) {
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    return current;
}

void generate(node_t **list) {
    int i, j, k, n, chars, words;
    for (i = 0; i<ITEMS_COUNT; i++) {
        item_t newItem;
        newItem.weight = randomReal(0.1, 100.0);
        newItem.price = randomReal(1.0, 1500.0);
        newItem.number = (uint16_t)i;


        words = randomInt(5, 10);
        newItem.description[0] = randomInt('A', 'Z');
        n = 1;
        for (j = 0; j<words; j++) {
            chars = randomInt(1, 10);
            for (k = 1; k<chars; k++) {
                newItem.description[n++] = randomInt('a', 'z');
            }
            newItem.description[n++] = ' ';
        }
        newItem.description[n++] = '\0';
        push(list, newItem);
    }
}

int main(void) {
    srand(time(NULL));
    int i;
    node_t *myList;
    generate(&myList);
    print_list(myList);
    listFree(&myList);
    exit(EXIT_SUCCESS);
}