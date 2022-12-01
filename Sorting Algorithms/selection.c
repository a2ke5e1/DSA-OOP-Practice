#include <stdio.h>
#include <stdlib.h>

void pA(int *, int *); 
void sort(int *, int *); 

void main() {
    int arr[] = {5,6,2,11,4,1,9};
    int n = sizeof(arr)/ sizeof(arr[0]); 
    sort(arr, &n); 
    printf("\n\n\n");
    pA(arr, &n);  
}

void sort(int *arr, int *n) {
    int i, j, temp, min_index; 
    for (i = 0; i < *n; i++ ) {
        min_index = i;
        for (j = i; j < *n; j++) {
            if (arr[j] < arr[min_index] ) {
                min_index = j; 
            }
        }
        temp = arr[i]; 
        arr[i] = arr[min_index]; 
        arr[min_index] = temp; 
        // 
        pA(arr, n);
    }
}

void pA(int *arr, int *n) {
    int i = 0; 
    for (i; i < *n; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n"); 
}