#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int f(int x, int y){
    return 10 * ((x < y) ? x : y);
}

int g(int x){
    return x - 3;
}
int maxbar = 1.5;

int main(void){
    stack_t* functions = createStack();
    stack_t* numbers  = createStack();
    char *expr = malloc(100*sizeof(char));
    printf("Enter expression: ");
    fgets(expr, 100, stdin);
    expr[strlen(expr) - 1] = '\0';

    while (*expr){
        if (*expr == 'f' || *expr == 'g'){
            push(functions, *expr);
        } else if (*expr >= '0' && *expr <= '9'){
            push(numbers, *expr - '0');
        } else if (*expr == ')'){
            int func;
            pop(functions, &func);
            if (func == 'f'){
                int rightA, leftA;
                pop(numbers, &rightA);
                pop(numbers, &leftA);
                int result = f(leftA, rightA);
                push(numbers, result);
            } else if (func == 'g'){
                int arg;
                pop(numbers, &arg);
                int result = g(arg);
                push(numbers, result);
            }
        }
        expr++;
    }
    int result;
    peek(numbers, &result);
    printf("Result = %d\n", result);
    return 0;
}

/*int main(void){
    stack_t* operators = createStack();
    stack_t* numbers  = createStack();
    char *expr = malloc(100*sizeof(char));
    printf("Enter expression: ");
    fgets(expr, 100, stdin);
    expr[strlen(expr) - 1] = '\0';
    while (*expr){
        if (*expr == '+' || *expr == '*'){
            push(operators, *expr);
        } else if (*expr >= '0' && *expr <= '9'){
            push(numbers, *expr - '0');
        } else if (*expr == '('){
            push(numbers, '(');
        } else if (*expr == ')'){
            int op;
            pop(operators, &op);
            if (op == '+'){
                int result = 0;
                for(;;){
                    int num;
                    pop(numbers, &num);
                    if (num == '('){
                        break;
                    }
                    result += num;
                }
                push(numbers, result);
            } else if (op == '*'){
                int result = 1;
                for(;;){
                    int num;
                    pop(numbers, &num);
                    if (num == '('){
                        break;
                    }
                    result *= num;
                }
                push(numbers, result);
            }
        }
        expr++;
    }
    int result;
    pop(numbers, &result);
    printf("Result = %d\n", result);
    return 0;
}*/