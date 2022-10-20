#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

void memoaryCheck(node *);

void print(node *);
void create();
void reverse();

void insertFirst();
void insertMiddle();
void insertLast();

void deleteFirst();
void deleteMiddle();
void deleteLast();

void searchList();
void count(); 

node *HEADER = NULL, *CURRENT = NULL, *t;

int main()
{
    int choice;
    int sub_choice;

    printf("Linked List Implementation\n");
    printf("\t1. Create\n");
    printf("\t2. Display\n");
    printf("\t3. Reverse\n");
    printf("\t4. Insert\n");
    printf("\t5. Search\n");
    printf("\t6. Delete\n");
    printf("\t7. Count\n");
    printf("\t10. Exit\n");

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
            reverse();
            break;
        case 4:
            printf("\nInsert");
            printf("\n\t1. At First");
            printf("\n\t2. At Middle");
            printf("\n\t3. At Last");

            printf("\n$ insert ~ ");
            scanf("%d", &sub_choice);

            switch (sub_choice)
            {
            case 1:
                /* Insert at first */
                insertFirst();
                break;
            case 2:
                /* Insert at middle */
                insertMiddle();
                break;
            case 3:
                /* Insert at last */
                insertLast();
                break;
            default:
                printf("================\n");
                break;
            }

            break;
        case 5:
            searchList();
            break;
        case 6:
            printf("\nDelete");
            printf("\n\t1. At First");
            printf("\n\t2. At Middle");
            printf("\n\t3. At Last");

            printf("\n$ delete ~ ");
            scanf("%d", &sub_choice);

            switch (sub_choice)
            {
            case 1:
                /* Delete at first */
                deleteFirst();
                break;
            case 2:
                /* Delete at middle */
                deleteMiddle();
                break;
            case 3:
                /* Delete at last */
                deleteLast();
                break;
            default:
                printf("================\n");
                break;
            }
            break;
        case 7: 
            count();
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
    for (node *i = x; i != NULL; i = i->next)
    {
        printf("%d->", i->data);
    }
    printf("NULL\n");
}

void create()
{
    t = (node *)malloc(sizeof(node));

    memoaryCheck(t);

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

void reverse()
{
    node *current = HEADER;
    node *next = NULL;
    node *prev = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    HEADER = prev;
}

void insertFirst()
{
    t = (node *)malloc(sizeof(node));

    memoaryCheck(t);

    printf("$ insert at first ~ ");
    scanf("%d", &t->data);

    if (HEADER == NULL)
    {
        t->next = NULL;
        HEADER = t;
    }
    else
    {
        t->next = HEADER;
        HEADER = t;
    }
}

void deleteFirst()
{
    if (HEADER == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *x;
        x = HEADER;
        HEADER = HEADER->next;
        free(x);
    }
}

void insertMiddle()
{
    printf("$ insert at middle | enter position ~ ");
    int pos, num;
    scanf("%d", &pos);
    node *x;
    x = HEADER;
    for (int i = 1; i < pos - 1; i++)
    {
        if (x->next == NULL)
        {
            printf("Pos doesn't exists\n");
            break;
        }
        x = x->next;
    }
    printf("$ insert at middle | enter number ~ ");
    scanf("%d", &num);
    t = (node *)malloc(sizeof(node));

    memoaryCheck(t);

    t->data = num;
    t->next = x->next;

    x->next = t;
}

void deleteMiddle()
{
    printf("$ delete at middle | enter position ~ ");
    int pos, num;
    scanf("%d", &pos);
    node *x;
    x = HEADER;

    if (pos == 1) {
        deleteFirst(); 
        return;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        if (x->next == NULL)
        {
            printf("Pos doesn't exists\n");
            break;
        }
        x = x->next;
    }
    node *z; 
    z = x->next;
    x->next = z->next; 
    free(z);

}

void insertLast()
{
    t = (node *)malloc(sizeof(node));

    memoaryCheck(t);

    printf("$ insert at last ~ ");
    t->next = NULL;
    scanf("%d", &t->data);

    if (HEADER == NULL)
    {
        t->next = NULL;
        HEADER = t;
    }
    else
    {
        node *i;
        for (i = HEADER; i->next != NULL; i = i->next)
            ;
        i->next = t;
        CURRENT = t;
    }
}

void deleteLast()
{

    if (HEADER == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        node *i;
        for (i = HEADER; i->next->next != NULL; i = i->next)
            ;
        free(i->next);
        i->next = NULL;
    }
}

void searchList()
{
    int num, f = 0;
    printf("$ search | number ~ ");
    scanf("%d", &num);
    node *s;
    s = HEADER;

    for (s; s != NULL; s = s->next)
    {
        if (s->data == num)
        {
            printf("Found Number: %d\n", num);
            f = 1;
        }
    }

    if (f == 0)
    {
        printf("Not found\n");
    }
}

void count() 
{
    int i = 0; 
    for (node *k = HEADER; k != NULL; k = k->next, i++);
    printf("%d\n", i); 
}