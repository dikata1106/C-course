#ifndef _STACK_H
#define _STACK_H

#include <stdlib.h>

typedef struct {
    int top;
    unsigned resize;
    unsigned size;
    unsigned capacity;
    int* arr;
} stack_t;

stack_t* createStack(void);
int isEmpty(stack_t* stack);
void push(stack_t* stack, int element);
int pop(stack_t* stack, int* value);
int peek(stack_t* stack, int *value);

#endif