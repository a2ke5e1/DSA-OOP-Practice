#include <stdio.h>

int binarySearch(int *, int, int, int); 

int main() {
    int array[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170}, x = 50, index, size = sizeof(array)/ sizeof(int); 
    index = binarySearch(array, x, 0, size); 
    index > - 1 ? printf("Found '%d' at index %d\n\n ", x, index) : printf("'%d' not found\n\n", x); 
    return 0; 
}

int binarySearch(int *arr, int x, int low, int high) {
    int mid = (low + high) / 2; 
    if (low > high) { return -1; } 
    else {
        if (arr[mid] == x) { return mid; }
        else if ( x > arr[mid] ) {
            return binarySearch(arr, x, mid + 1, high); 
        } else if ( x < arr[mid] ) {
            return binarySearch(arr, x, low, mid - 1); 
        }

    }
}