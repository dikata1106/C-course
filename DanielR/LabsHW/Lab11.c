#include <stdio.h>

const int MAXSIZE = 100;       
char stack[100];     
int top = -1;            

int isempty(void) {
   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull(void) {
   if(top == MAXSIZE)
      return 1;
   else
      return 0;
}

char peek(void) {
    if(!isempty())
        return stack[top];
    else{
        printf("Could not retrieve data, Stack is empty.\n");
        return '\0';
    }
}

char pop(void) {
   char data;
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(char data) {
   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
      return 0;
   } else {
      printf("Could not insert data, Stack is full.\n");
      return 1;
   }
}

int main(void) {
    char c;

    while((c=getchar()) != '\n') {
        if (c=='(' || c=='[' || c=='<')
            push(c);
        else if (c==']' && peek()=='[')
            c=pop();
        else if (c==')' && peek()=='(')
            c=pop();
        else if (c=='>' && peek()=='<')
            c=pop();
        else   
            break;
    }
    if (c=='\n' && isempty())
        printf("Valid sequence\n");
    else
        printf("Invalid sequence\n");

}