#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// NE OPISVA KADE DA SE SAHRANIAVAT LICATA NA PRAVOUGULNICITE
// SHTE SE DOBAVIAT V rectangle_t SPORED FUNKCIITE SHTOM NE E OPISANO

typedef struct {
    double x, y;
} point_t;

typedef struct {
    point_t A, B;
    double area;
} rectangle_t;

typedef struct node {
    rectangle_t data;
    struct node* next;
} node_t;

#define COUNT 10

double randomReal(double min, double max) {
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

node_t* create_node(rectangle_t data){
    node_t* node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void print(node_t* list){
    node_t* current = list;
    // while (current){
    for (int i=0; i<COUNT; i++) {
        printf("A(%.4lf, %.4lf) B(%.4lf, %.4lf) Area = %.4lf\n", current->data.A.x, current->data.A.y, current->data.B.x, current->data.B.y, current->data.area);
        current = current->next;
    }
    putchar('\n');
}

void listFree(node_t** list){
    node_t *current = *list, *prev;
    //for (int i = 0; i<COUNT; i++){
    while (current) {
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

//Да се направи функция, която изчислява лицето на всички правоъгълници
double areaRects(node_t* list) {
    double areaTot = 0.0, area = 0.0;
    node_t* current = list;
    //printf("AA\n");
    // while (current != NULL){
    for (int i=0; i<COUNT; i++) {
        //printf("AAA\n");
        area = fabs(current->data.A.x - current->data.B.x) * fabs(current->data.A.y - current->data.B.y);
        current->data.area = area;
        areaTot += area;
        current = current->next;
    }
    return areaTot;
}

void filterRects(node_t** list, double min, double max) {
    node_t *current = *list, *prev;
    prev = current;
    current = prev->next;
    while (current != NULL) {
        if (current->data.area<min || current->data.area>max) {
            prev->next = current->next;
            current->next = NULL;
            free(current);
            current = prev->next;
        } else {
            prev = current;
            current = prev->next;
        }
    }
    if ((*list)->data.area<min || (*list)->data.area>max) {
            current = (*list);
            (*list) = (*list)->next;
            free(current);
        }
}

int main(void) {
    srand(time(NULL));
    rectangle_t rec;
    node_t *myList, *aux;
    int i;
    for (i=0; i<COUNT; i++) {
        rec.A.x = randomReal(1.0, 10.0);
        rec.A.y = randomReal(1.0, 10.0);
        rec.B.x = randomReal(1.0, 10.0);
        rec.B.y = randomReal(1.0, 10.0);
        aux = create_node(rec);
        aux->next = myList;
        myList = aux;
    }
    areaRects(myList);
    print(myList);
    filterRects(&myList, 1.0, 5.0);
    print(myList);
    listFree(&myList);
    return EXIT_SUCCESS;
}