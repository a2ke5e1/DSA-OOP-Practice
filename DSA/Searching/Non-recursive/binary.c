#include <stdio.h>

int binarySearch(int *, int, int, int);

int main()
{
    int array[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 110, index, size = (sizeof(array) / sizeof(int));
    index = binarySearch(array, 0, size, x);
    index > -1 ? printf("Found '%d' at index %d\n\n ", x, index) : printf("'%d' not found\n\n", x);
    return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;

        if (arr[m] == x)
        {
            return m;
        }

        if (arr[m] < x)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }

    return -1;
}