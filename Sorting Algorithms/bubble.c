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
    int i = 0, j, temp; 
    for (i = 0; i < *n - 1; i++ ) {
        for (j = 0; j < *n - i - 1; j++) {
            if (arr[j+1] < arr[j] ) {
                temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            }

            // 
            pA(arr, n);
        }
        //
        printf("\n\n");
    }
}

void pA(int *arr, int *n) {
    int i = 0; 
    for (i; i < *n; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n"); 
}