#include <stdio.h>

void print_array(int *, int); 
void bubble_sort(int *, int); 


int main() {

    // unsortted array 
    int array[] =  { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(array) / sizeof(array[0]); 

    bubble_sort(array, size); 

    print_array(array, size); 

    return 0; 
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n\n"); 
}


void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ( arr[j] > arr[j+1]) {
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp; 
            }
        }
    }
}