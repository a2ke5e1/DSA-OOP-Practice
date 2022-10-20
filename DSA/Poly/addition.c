#include <stdio.h>
#include <stdlib.h>

struct node
{
    int cof;
    int exp;
    struct node *next;
};
typedef struct node node;

node *create(node *HEAD)
{
    int i, n;
    int c, e;
    node *CUR = HEAD;
    printf("Enter no. of elements: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        node *t = (node *)malloc(sizeof(node));
        printf("Enter coffcient: ");
        scanf("%d", &t->cof);
        printf("Enter expo: ");
        scanf("%d", &t->exp);

        t->next = NULL;

        if (HEAD == NULL)
        {
            HEAD = t;
            CUR = t;
        }
        else
        {
            CUR->next = t;
            CUR = t;
        }
    }

    return HEAD;
}

void printNode(node *NODE)
{

    for (node *i = NODE; i != NULL; i = i->next)
    {
        printf("%dx^%d ", i->cof, i->exp);
        if ( i->next != NULL) {
            printf("+ ");
        }
    }
}

node *add(node *A, node *B)
{
    node *c = NULL;
    node *z;
    node *x = A, *y;
    while (x != NULL)
    {
        y = B;
        while (y != NULL)
        {
            if (x->exp == y->exp)
            {
                node *t = (node *)malloc(sizeof(node));

                t->exp = x->exp;
                t->cof = x->cof + y->cof;
                t->next = NULL;
                if (c == NULL)
                {
                    c = t;
                    z = t;
                }
                else
                {
                    z->next = t;
                    z = t;
                }
            } 
            y = y->next;
        }
        
        x = x->next;
    }
    return c;
}

int main()
{
    node *HEAD_A = NULL, *HEAD_B = NULL, *HEAD_C;
    HEAD_A = create(HEAD_A);
    printNode(HEAD_A);
    HEAD_B = create(HEAD_B);
    printNode(HEAD_B);
    HEAD_C = add(HEAD_A, HEAD_B);
    printf("\n\nAns\n");
    printNode(HEAD_C); 
    return 0;
}
