#include <stdio.h>
int a[100], n;
void quickSort(int first, int last)
{
    if (first < last)
    {
        int pivot = first;
        int i = first;
        int j = last;

        while (i < j)
        {
            while (a[i] <= a[pivot] && i < last)
                i++;
            while (a[j] > a[pivot])
                j--;

            if (i < j)
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        int temp = a[pivot];
        a[pivot] = a[j];
        a[j] = temp;

        quickSort(first, j - 1);
        quickSort(j + 1, last);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}