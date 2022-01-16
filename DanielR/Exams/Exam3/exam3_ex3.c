#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* create_node(int data){
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void listFree(struct Node** list){
    if (*list == NULL) {
        return;
    }
    struct Node *current = (*list)->next, *prev = *list;
    free(prev);
    while (current != *list){
        prev = current;
        current = current->next;
        free(prev);
    }
    *list = NULL;
}

void print(struct Node *cll){
    if (cll == NULL) {
        return;
    }
    struct Node* current = cll->next;
    printf("%d ", cll->data);
    while (current != cll){
        printf("%d ", current->data);
        current = current->next;
    }
    putchar('\n');
}

struct Node* insertAfter(struct Node *cll, int skipCount, int newElem) {
    int i = 1;
    struct Node *aux = cll, *newNode;
    if (skipCount <= 0 || skipCount > 1000000) {
        printf("Invalid SkipCount\n");
        // cannot insert after 0 (first item), cause cant modify cll as the function is defined (*cll instead of **cll)
        return NULL;
    }
    if (cll == NULL) {
        cll = create_node(newElem);
        return cll;
    }
    while (i<skipCount) {
        aux = aux->next;
        i++;
    }
    newNode = create_node(newElem);
    newNode->next = aux->next;
    aux->next = newNode;
    return newNode;
}

int main(void) {

    int N, num, i;
    struct Node *myCLL = NULL, *aux;
    printf("Insert number of items\n");
    scanf("%d", &N);
    if (N <= 0) {
        printf("Invalid number\n");
        return EXIT_FAILURE;
    }
    printf("Insert numbers separated with space\n");
    for (i=0; i<N; i++) {
        fscanf(stdin, "%d", &num);
        // printf("%d\n", num);
        struct Node *newNode = create_node(num);
        if (myCLL == NULL) {
            myCLL = newNode;
            newNode->next = newNode;
        } else {
            aux = myCLL->next;
            while (aux->next != myCLL) {
                aux = aux->next;
            }
            aux->next = newNode;
            newNode->next = myCLL;
            myCLL = newNode;
        }
    }
    print(myCLL);
    aux = insertAfter(myCLL, 5, 99);
    if (aux != NULL) {
        printf("Insert %d after skipCount = 5\n", aux->data);
    }
    print(myCLL);
    listFree(&myCLL);
    return EXIT_SUCCESS;
}