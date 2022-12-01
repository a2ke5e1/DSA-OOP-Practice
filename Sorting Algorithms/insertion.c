#include <stdio.h>
#include <stdlib.h>

void pA(int *, int *);
void sort(int *, int *);

void main()
{
    int arr[] = {5, 6, 2, 11, 4, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, &n);
    printf("\n\n\n");
    pA(arr, &n);
}

void sort(int *arr, int *n)
{
    int i, j, key;
    for (i = 1; i < *n; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0 ; j--)
        {
            if ( key > arr[j]) {
                break;
            }
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void pA(int *arr, int *n)
{
    int i = 0;
    for (i; i < *n; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}