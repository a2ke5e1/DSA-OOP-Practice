#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *newNode(int n)
{
    node *t = (node *)malloc(sizeof(node));
    t->data = n;
    t->left = NULL;
    t->right = NULL;

    return t;
}

void printInorder(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->data);

    /* now recur on right child */
    printInorder(node->right);
}

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;

    /* first print data of node */
    printf("%d ", node->data);

    /* then recur on left subtree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

void printPostorder(struct node *node)
{
    if (node == NULL)
        return;

    // first recur on left subtree
    printPostorder(node->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->data);
}

void main()
{
    node *root = newNode(1);
    root->left = newNode(2);

    root->left->left = newNode(4);
    root->left->right = newNode(5);

    
    root->right = newNode(3);

    /*
    
                    1
                2       3
              4   5
    
    */

    printInorder(root);
    printf("\n");

    circle(0   , 0, 15);
}