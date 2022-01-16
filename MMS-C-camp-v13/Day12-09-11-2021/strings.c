#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct node {
    int data;
    struct node* next;
} node_t;

void push(node_t** stack, int element){
    node_t* n = malloc(sizeof(node_t));
    n->data = element;
    n->next = *stack;
    *stack = n;
}


int isEmpty(node_t* stack){
    return stack == NULL;
}

int pop(node_t** stack, int *value){
    if (isEmpty(*stack)){
        return -1;
    }
    *value = (*stack)->data;
    node_t* temp = *stack;
    *stack = (*stack)->next;
    free(temp);
    return 0;
}

int peek(node_t* stack){
    return stack->data;
}

int main(void){
    node_t* stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    while (!isEmpty(stack)){
        int n;
        pop(&stack, &n);
        printf("%d ", n);
    }
    putchar('\n');
    int n;
    if (pop(&stack, &n) == -1){
        printf("Stack is empty!\n");
        return -1;
    }
    printf("n = %d\n", n);
    /*
    char** str = malloc(sizeof(char*)*N);
    for (int i = 0; i < N; i++){
        str[i] = malloc(sizeof(char)*(i+2));
    } 

    for (int i = 0; i < N; i++){
        memset(str[i], '$', i+1);
        str[i][i+2] = '\0';
    } 

    for (int i = 0; i < N; i++){
        printf("%s\n", str[i]);
    }

    for (int i = 0; i < N; i++){
        free(str[i]);
    }
    free(str); 
    return 0;
}