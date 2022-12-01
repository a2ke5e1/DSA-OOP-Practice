#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STACK_MAX_SIZE 10

typedef struct stack
{
    int stack[STACK_MAX_SIZE];
    int top;

} stack;

void init(stack *s)
{
    s->top = -1; 
}

bool isFull(stack *s)
{
   return s->top >= STACK_MAX_SIZE - 1;  
}

bool isEmpty(stack *s) 
{
    return s->top == -1; 
}

void push(stack *s, int data)
{
    if (isFull(s))
    {
        printf("Stack Overflow"); 
        return; 
    }
    s->stack[++s->top] = data; 
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow"); 
        return -1 * STACK_MAX_SIZE; 
    }

    return s->stack[s->top--]; 
}

int peek(stack *s)
{
    return s->stack[s->top]; 
}

void main() {
    stack s; 
    init(&s); 

    push(&s, 12); 
    push(&s, 13); 

    printf("%d", pop(&s)); 
}
