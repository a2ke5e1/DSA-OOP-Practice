#include <stdio.h>
#include <stdlib.h>

#define EMPTY_STACK -4

typedef struct stack {
    int capacity;  
    int top; 
    int *items;
} stack; 

stack* create_stack(int); 


void display(stack *); 
void push(stack *, int);
int pop(stack *); 

int main() {
    int size, x, choice; 
    printf("Enter Size of the Stack: "); 
    scanf("%d", &size); 
    stack *s = create_stack(size); 
    printf("\nStack Implementation using Struct\n"); 
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n\n"); 
    do {
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) {
            case 1: {
                printf("Enter the element: "); 
                scanf("%d", &x); 
                push(s, x); 
                break;
            }
            case 2: {
                pop(s); 
                break; 
            }
            case 3: {
                display(s); 
                break;
            }
            case 4: exit(1); 
            default: {
                printf("Invalid Choice");
            }
        }
    } while ( choice != 4);
    free(s); 
    return 0; 
}

stack* create_stack(int capacity) {
    stack *s = (stack *)malloc(sizeof(stack)); 
    s->capacity = capacity; 
    s->top = -1; 
    int *items = (int *)malloc(sizeof(capacity)); 
    s->items = items; 
    return s; 
}

void display(stack *s) {
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->items[i]); 
    }
    printf("\n");
}

void push(stack *s, int i) {
    if (s->top == s->capacity - 1) {
        printf("Stack is full\n"); 
        return; 
    }
    s->top++; 
    s->items[s->top] = i; 
}

int pop(stack *s) {
    if ( s-> top == -1) {
        printf("Stack  is Empty");
        return EMPTY_STACK;
    }
    int temp = s->items[s->top]; 
    s->top--; 
    return temp;
}