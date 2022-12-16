#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next; 
    struct node *prev;
} node; 

void create(node **, int); 
void display(node **);

void main() {
    node *HEAD = NULL;
    create(&HEAD , 8);
    display(&HEAD); 
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
            
            t->prev = NULL; 
            
            *HEAD = t; 
            CURR = t; 

        } else {

            t->next = NULL; 
            t->prev = CURR;

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