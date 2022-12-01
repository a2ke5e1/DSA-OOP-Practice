// Delete multiples of 3 from array
#include <stdlib.h>
#include <stdio.h>

void print_array(int *, int *);
void reverse(int *, int *); 
void swap(int *, int *); 
void delete_element(int *, int *, int);

void main() {
    int i, n, *a; 
    printf("Enter number of elements: "); 
    scanf("%d", &n); 

    a = (int *)malloc(sizeof(int)*n); 

    printf("Enter Elements: \n"); 
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]); 
    }

    printf("You Entered: "); 
    print_array(a, &n); 

    // Reverse Array
    reverse(a,&n); 

    printf("Result: \n"); 
    print_array(a, &n); 

}

void print_array(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

void reverse(int *arr, int *n) {
    int i = 0; 
    for (i = 0; i < *n / 2 ; i++) {
        swap(&arr[i], &arr[*n-i-1]); 
    }
}

void swap(int *a, int *b) {
    // int temp = *b; 
    // *b = *a; 
    // *a = temp; 

    *b = *a + *b; 
    *a = *b - *a; 
    *b = *b - *a; 
}

void delete_element(int *arr, int *n, int i) {
    for ( int x = i; x < *n - 1; x++) {
        arr[x] = arr[x+1]; 
    }
    *n = *n - 1; 
}