#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next; 
} node; 

void create(node **, int); 
void display(node **); 

void enqueue(node **, int); 
int dequeue(node **); 

void main() {
    node *QUEUE = NULL; 

    create(&QUEUE, 0); 

    enqueue(&QUEUE, 5); 
    enqueue(&QUEUE, 6); 
    enqueue(&QUEUE, 7); 
    enqueue(&QUEUE, 8); 

    display(&QUEUE); 


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

void enqueue(node **HEAD, int data) {
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

int dequeue(node **HEAD) {
    node *x;
    int d;  
    if ( *HEAD == NULL) {
        printf("List is Empty"); 
        return; 
    }

    x = *HEAD; 
    *HEAD = (*HEAD)->next; 
    d = x->data; 
    free(x); 

    return d; 
}