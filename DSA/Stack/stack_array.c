#include <stdio.h>

int stacks[100], top = -1, end = 100; 

void display() {
    if (top == -1) {
        printf("Stack is Empty"); 
        return; 
    }

    for (int i = top; i >= 0; i--) {
        printf("%d\n", stacks[i]); 
    }
}

void push(int i) {
    if ( top >= end - 1) {
        printf("Stack is Full\n");
        return;  
    }
    top++;
    stacks[top] = i; 
}
int pop() {
    int temp; 
    if ( top == -1) {
        printf("Stack is Empty\n");
        return -1;  
    }
    temp = stacks[top]; 
    top--; 
    return temp; 
}


int main() {
    int exit = 0;
    int option;
    printf("Select your task: \n"); 
    printf("1. Display stack\n");  
    printf("2. push stack\n");  
    printf("2. pop stack\n"); 
    printf("9. exit");

    do {
        printf("\n~ "); 
        scanf("%d", &option);
        switch(option)  {
            case 1: {
                display(); 
                break;
            }
            case 2: {
                printf("Enter a number: \n"); 
                int x; 
                scanf("%d", &x); 
                push(x); 
                break;
            }
            case 3: {
                printf("Deleted %d\n", pop());
                break;
            }
            case 9: {
                exit = 1; break;
            }
            default: break;
        };      
    } while ( exit == 0); 
    return 0; 
}