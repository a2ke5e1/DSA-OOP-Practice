#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data; 
    struct node *next; 
} node; 

void create(node **, int); 
void display(node **); 

void insert_start(node **, int); 
void insert_mid(node **, int, int); 
void insert_end(node **, int); 
void delete_start(node **); 
void delete_mid(node **, int); 
void delete_end(node **); 

void main() {
    node *HEAD = NULL; 
    create(&HEAD, 5); 
    display(&HEAD);

    insert_start(&HEAD, 100); 
    display(&HEAD); 

    delete_start(&HEAD); 
    insert_end(&HEAD, 1001); 
    display(&HEAD); 

    insert_mid(&HEAD, 3, 1021);  
    display(&HEAD); 

    
    delete_end(&HEAD);
    display(&HEAD); 
    delete_mid(&HEAD, 3);
    display(&HEAD); 

}

void insert_start(node **HEAD, int data) {
    node *t; 
    t = (node *)malloc(sizeof(node)); 
    t->data = data; 

    if ( *HEAD == NULL) {
        t->next = NULL;
        *HEAD = t; 
    } else {
        t->next = *HEAD; 
        *HEAD = t;
    }  
}


void insert_mid(node **HEAD, int key, int data) {
    node *t, *x, *y; 
    t = (node *)malloc(sizeof(node)); 
    t->data = data; 

    if ( *HEAD == NULL) {
        printf("Linked List is Empty"); 
        return; 
    }

    x = *HEAD; 
    for ( y = x; y != NULL; y = y->next, x = x->next) {
        if ( y->data == key) {
            t->next = x->next;
            x->next = t;
        }
    } 
        
}

void insert_end(node **HEAD, int data) {
    node *t, *x; 
    t = (node *)malloc(sizeof(node)); 
    t->data = data; 
    t->next = *HEAD; 

    if ( *HEAD == NULL) {
        *HEAD = t; 
    } else {
        for ( x = *HEAD; x->next != NULL; x = x->next); 
        x->next = t; 
    }  
}


void delete_start(node **HEAD) {
    node *x; 
    if ( *HEAD == NULL) {
        printf("List is Empty"); 
        return; 
    }

    x = *HEAD; 
    *HEAD = (*HEAD)->next; 
    free(x); 

}

void delete_end(node **HEAD) {
    node *x, *y; 
    if ( *HEAD == NULL) {
        printf("List is Empty"); 
        return; 
    }
   for ( x = *HEAD, y = x->next; y->next != NULL; y= y->next, x = x->next);

    free(y); 
    x->next = NULL;

}

void delete_mid(node **HEAD, int key) {
    node *x, *y; 

    if ( *HEAD == NULL) {
        printf("Linked List is Empty"); 
        return; 
    }

    x = *HEAD; 

    if ( x->data == key) {
        delete_start(HEAD); 
        return; 
    }

    for ( y = x->next; y != NULL; y = y->next, x = x->next) {
        if ( y->data == key) {
            x->next = y->next; 
            free(y); 
           break;
        }
    }       
}


void create(node **HEAD, int elements_count) {
    node *CURR = NULL, *t = NULL; 
    int i = 0; 
    for (i; i < elements_count; i++) {
        t = (node *)malloc(sizeof(node)); 
        printf("~ ");
        scanf("%d", &t->data);

        if ( *HEAD == NULL) {
            
            t->next = t; 
            
            *HEAD = t; 
            CURR = t; 

        } else {

            t->next = *HEAD; 

            CURR->next = t;
            CURR = t;
        }

    }
}

void display(node **HEAD) {
    node *i; 
    i = *HEAD;
    if ( *HEAD == NULL) {
        printf("Linked List is empty"); 
        return; 
    }
    do {
        printf("%d ", i->data); 
        i = i->next;
        
    } while (*HEAD != i); 
}