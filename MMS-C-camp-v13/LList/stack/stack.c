#include "stack.h"

stack_t* createStack(void){
    stack_t* stack = malloc(sizeof(stack_t));
    stack->capacity = 10;
    stack->resize = 10;
    stack->size = 0;
    stack->top = -1;
    stack->arr = malloc(stack->capacity * sizeof(int));
    return stack;
}

int isEmpty(stack_t* stack){
    return stack->size == 0;
}

void push(stack_t* stack, int element){
    if (stack->size == stack->capacity){
        stack->capacity += stack->resize;
        stack->arr = realloc(stack->arr, sizeof(int)*stack->capacity);
    }
    stack->arr[++stack->top] = element;
    stack->size++;
}

int pop(stack_t* stack, int* value){
    if(isEmpty(stack)){
        return -1;
    }
    *value = stack->arr[stack->top--];
    stack->size--;
    if (stack->capacity > stack->size + stack->resize){
        stack->capacity -= stack->resize;
        stack->arr = realloc(stack->arr, sizeof(int)*stack->capacity);
    }
    return 0;
}

int peek(stack_t* stack, int *value){
    if(isEmpty(stack)){
        return -1;
    }
    *value = stack->arr[stack->top];
}
