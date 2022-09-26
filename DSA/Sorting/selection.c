#include <stdio.h>

void print_array(int *, int); 
void selection_sort(int *, int); 


int main() {

    // unsortted array 
    int array[] =  { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(array) / sizeof(array[0]); 

    selection_sort(array, size); 

    // sorted array
    print_array(array, size); 

    return 0; 
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n\n"); 
}


void selection_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i; 
        for (int j = i + 1; j < size; j++)  {
            if ( arr[j] < arr[min_index]) {
                min_index = j; 
            }
        }
        // Swap
        int temp = arr[i]; 
        arr[i] = arr[min_index]; 
        arr[min_index] = temp; 
    }
}