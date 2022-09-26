#include <stdio.h>

void print_array(int *, int); 

void swap(int *,int *);
int partition(int *, int , int);  
void quick_sort(int *, int, int);

int main() {

    // unsortted array 
    int array[] =  { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(array) / sizeof(array[0]); 

    quick_sort(array, 0, size - 1); 

    print_array(array, size); 

    return 0; 
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n\n"); 
}


void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    }
}


void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1 ); 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
             
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+ 1], &arr[high]); 
    return (i + 1);  // returns pivot point 
}