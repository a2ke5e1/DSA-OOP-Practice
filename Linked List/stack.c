#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next; 
} node; 

void create(node **, int); 
void display(node **); 

void push(node **, int); 
int pop(node **); 
int peek(node **); 

void main() {
    node *STACK = NULL; 

    create(&STACK, 5); 

    push(&STACK, 150);

    display(&STACK); 

    printf("Pop: %d\n", pop(&STACK) ); 
    printf("Peek: %d\n", peek(&STACK)); 

    display(&STACK); 
   

}

void create(node **HEAD, int elements_count) {
    node *CURR = NULL, *t = NULL; 
    int i = 0; 
    for (i; i < elements_count; i++) {
        t = (node *)malloc(sizeof(node)); 
        printf("~ ");
        scanf("%d", &t->data);
        t->next = NULL; 

        if ( *HEAD == NULL) {
            *HEAD = t; 
            CURR = t; 
        } else {
            CURR->next = t;
            CURR = t;
        }

    }
}

void display(node **HEAD) {
    node *i; 
    if ( *HEAD == NULL) {
        printf("Linked List is empty"); 
        return; 
    }
    for (i = *HEAD; i != NULL; i = i->next) {
        printf("%d->", i->data); 
    }
    printf("NULL\n"); 
}


void push(node **HEAD, int data) {
    node *t, *x; 
    t = (node *)malloc(sizeof(node)); 
    t->data = data; 
    t->next = NULL; 

    if ( *HEAD == NULL) {
        *HEAD = t; 
    } else {
        for ( x = *HEAD; x->next != NULL; x = x->next); 
        x->next = t; 
    }  
}


int pop(node **HEAD) {
    node *x, *y; 
    int d; 
    if ( *HEAD == NULL) {
        printf("List is Empty"); 
        return -1; 
    }
   for ( x = *HEAD, y = x->next; y->next != NULL; y= y->next, x = x->next);

    d = y->data; 
    free(y); 
    x->next = NULL;
    return d; 

}

int peek(node **HEAD) {
    node *x; 
    for (x = *HEAD; x->next != NULL; x = x->next); 
    return x->data; 
}