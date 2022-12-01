// Delete multiples of 3 from array
#include <stdlib.h>
#include <stdio.h>

void print_array(int *, int *);
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

    for (i = 0; i < n; i++) {
        if ( a[i] % 3 == 0) {
            delete_element(a, &n, i); 
            // This make sures that shifted number is also divisble by 3 or not.
            i--;
        }
    }

    printf("Result: \n"); 
    print_array(a, &n); 

}

void print_array(int *arr, int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n"); 
}

void delete_element(int *arr, int *n, int i) {
    for ( int x = i; x < *n - 1; x++) {
        arr[x] = arr[x+1]; 
    }
    *n = *n - 1; 
}