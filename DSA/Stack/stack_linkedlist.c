#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void memoaryCheck(node *);
void print(node *);

void push();
node pop();

node *HEADER = NULL, *CURRENT = NULL;

int main()
{
    int choice;

    printf("Stack Implementation using Linked List \n");
    printf("\t1. Display\n");
    printf("\t2. push\n");
    printf("\t3. pop\n");
    printf("\t10. Exit\n");

    do
    {
        printf("$ ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            print(HEADER);
            break;
        case 2:
            push(CURRENT);
            break;
        case 3:
            pop(CURRENT);
            break;
        case 10:
            exit(1);
        default:
            printf("Invalid Choice\n");
            break;
        }

    } while (choice != 10);

    return 0;
}

void memoaryCheck(node *x)
{
    if (x == NULL)
    {
        printf("\n=========================\n");
        printf("\n\nMemoary Allocation Failed\n\n");
        printf("\n=========================\n");
        exit(1);
    }
}

void print(node *x)
{

    if (x == NULL)
    {
        printf("Stack is Empty\n");
        return;
    }

    for (node *i = x; i != NULL; i = i->next)
    {
        printf("\n----");
        printf("\n|%d|", i->data);
    }
    printf("----\n");
}

void push()
{
    node *t;
    t = (node *)malloc(sizeof(node));
    printf("$ push ~ ");
    scanf("%d", &t->data);
    t->next = NULL;

    memoaryCheck(t);

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

node pop()
{
    node *i;
    node z = *CURRENT;
    if (HEADER->next == NULL)
    {
        z = *HEADER;
        free(HEADER);
        HEADER = NULL;
        return z;
    }

    free(CURRENT);

    for (i = HEADER; i->next == NULL; i = i->next)
        ;
    i->next = NULL;
    CURRENT = i;
    return z;
}