#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node_t;

typedef struct list {
    node_t *first;
    node_t *last;
    int size;
} list_t;

list_t * createList(void) {
    list_t *newList = (list_t *)malloc(sizeof(list_t));
    if (!newList) {
        fprintf(stderr, "Can not create new list\n");
        return NULL;
        
    }
    newList->first = newList->last = NULL;
    newList->size = 0;
    return newList;
}

void deleteNodes(list_t **list) {
    node_t *aux;
    while ((*list)->first != NULL) {
        aux = (*list)->first;
        (*list)->first = (*list)->first->next;
        aux->next = NULL;
        if ((*list)->first == NULL) {
            (*list)->last = NULL;
        } else {
            (*list)->first->prev = NULL;
        }
        // printf("FREE %d\n", aux->data);
        free(aux);
        (*list)->size--;
    }
    if ((*list)->first != NULL) {   // *first == *last
        // printf("FREE %d\n", aux->data);
        free((*list)->first);
    }
    // if ((*list)->first == (*list)->last) {   // *first == *last
    //     printf("first = last\n");
    // }
}

void deleteList(list_t **list) {
    deleteNodes(list);
    // if(((*list)->first) == NULL)
    //     printf("first node null\n");
    // else
    //     printf("first node not null\n");
    // if(((*list)->last) == NULL)
    //     printf("last node null\n");
    // else
    //     printf("last node not null\n");
    free(*list);
}

void addFront(list_t *list, int data) {
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    node_t *aux = list->first;
    if (!newNode) {
        fprintf(stderr, "Can not create new node\n");
        return;
    }
    newNode->data = data;
    newNode->next = aux;
    newNode->prev = NULL;
    list->first = newNode;
    if (aux == NULL) {
        list->last = newNode;
    } else {
        aux->prev = newNode;
    }
    list->size += 1;
}

void addBack(list_t *list, int data) {
    node_t * newNode = (node_t *)malloc(sizeof(node_t));
    node_t *aux = list->last;
    if (!newNode) {
        fprintf(stderr, "Can not create new node\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = aux;
    list->last = newNode;

    if (aux == NULL) {
        list->first = newNode;
    } else {
        aux->next = newNode;
    }
    list->size += 1;
}

void printListFL(list_t *list) {
    node_t *aux = list->first;
    printf("F -> ");
    while(aux != list->last) {
        printf("%d <=> ", aux->data);
        aux = aux->next;
    }
    if (aux != NULL) {   // first == last
        printf("%d", aux->data);
    }
    printf(" <- L\n");
}

void printListLF(list_t *list) {
    node_t *aux = list->last;
    printf("L -> ");
    while(aux != list->first) {
        printf("%d <=> ", aux->data);
        aux = aux->prev;
    }
    if (aux != NULL) {   // first == last
        printf("%d", aux->data);
    }
    printf(" <- F\n");
}

int removeFront(list_t *list) {
    if (list->first == NULL) {
        return -1;
    }
    int data = list->first->data;
    node_t *aux = list->first;
    list->first = list->first->next;
    aux->next = NULL;
    if (list->first == NULL) {
        list->last = NULL;
    } else {
        list->first->prev = NULL;
    }
    free(aux);
    list->size--;
    return data;
}

int removeBack(list_t *list) {
    if (list->last == NULL) {
        return -1;
    }
    int data = list->last->data;
    node_t *aux = list->last;
    list->last = list->last->prev;
    aux->prev = NULL;
    if (list->last == NULL) {
        list->first = NULL;
    } else {
        list->last->next = NULL;
    }
    free(aux);
    list->size--;
    return data;
}

int numElements(list_t *list) {
    return list->size;
}

int isEmpty(list_t *list) {
    return list->size == 0;
}

int main(void) {

    /**
     * createList
     * addFront
     * addBack
     * removeFront
     * removeBack
     * printListLF
     * printListFL
     * isEmpty
     * numElements
     * deleteNodes
     * deleteList
     * 
     * // TODO :
     * 
     * removeNodeX
     * removeValueX
     * removeIndexX
     * addBeforeNodeX
     * addBeforeValueX
     * addBeforeIndexX
     * addAfterNodeX
     * addAfterValueX
     * addAfterIndexX
     * changeValueNodeX
     * changeValueValueX
     * changeValueIndexX
     * 
     * merge
     * mergeSort
     * 
     * Iterator
     */


    int i;
    list_t *myList = createList();
    addFront(myList, 5);
    addBack(myList, 6);
    addFront(myList, 4);
    addBack(myList, 7);
    addFront(myList, 3);
    printf("Size: %d\n", numElements(myList));
    printListFL(myList);
    printListLF(myList);
    
    // while (!isEmpty(myList)) {
    //     i = removeFront(myList);
    //     printf("Remove %d, new size: %d\n", i, numElements(myList));
    //     printListFL(myList);
    //     printListLF(myList);
    // }
    // i = removeFront(myList);
    // printf("Remove %d, new size: %d\n", i, numElements(myList));
    
    // while (!isEmpty(myList)) {
    //     i = removeBack(myList);
    //     printf("Remove %d, new size: %d\n", i, numElements(myList));
    //     printListFL(myList);
    //     printListLF(myList);
    // }
    // i = removeBack(myList);
    // printf("Remove %d, new size: %d\n", i, numElements(myList));
    
    // deleteNodes(&myList);
    printListFL(myList);
    printListLF(myList);
    deleteList(&myList);
    return 0;
}