#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void print(node *);
void create();

node *HEADER = NULL, *CURRENT = NULL, *t;

int main()
{
    int choice;

    printf("Linked List Implementation\n");
    printf("\t1. Create\n");
    printf("\t2. Display\n");
    printf("\t3. Exit\n");

    do
    {
        printf("$ ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            print(HEADER);
            break;
        case 3:
            exit(1);
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 3);

    return 0;
}

void print(node *x)
{
    for (node *i = x; i != NULL; i = i->next)
    {
        printf("%d->", i->data);
    }
    printf("NULL\n");
}

void create()
{
    t = (node *)malloc(sizeof(node));
    printf("$ create ~ ");
    scanf("%d", &t->data);
    t->next = NULL;
    if (HEADER == NULL)
    {
        HEADER = t; 
        CURRENT = t; 
    }
    else
    {
        CURRENT->next = t; 
        CURRENT = t; 
    }
}
