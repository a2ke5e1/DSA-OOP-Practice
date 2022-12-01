#include <stdio.h>
#include <stdlib.h>

void pA(int *, int *); 
void sort(int *, int *); 

void quick_sort(int *, int, int); 
int parition(int *, int, int); 
void swap(int *, int *); 

void main() {
    int arr[] = {5,6,2,11,4,1,9};
    int n = sizeof(arr)/ sizeof(arr[0]); 
    sort(arr, &n); 
    printf("\n\n\n");
    pA(arr, &n);  
}

void sort(int *arr, int *n) {
    quick_sort(arr,0, *n-1); 
}

void quick_sort(int *arr, int start, int end) {
    if ( start < end) {
        int pi = parition(arr, start, end); 

        quick_sort(arr, start, pi - 1); 
        quick_sort(arr, pi+1, end); 
    }
}

int parition(int *arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1 ); 
 
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+ 1], &arr[high]); 
    return (i + 1);
}

void swap(int *a, int *b) {
    int temp = *b; 

    *b = *a; 
    *a = temp; 
}

void pA(int *arr, int *n) {
    int i = 0; 
    for (i; i < *n; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n"); 
}