#include <stdio.h>

void print_array(int *, int); 

void swap(int *,int *);
int partition(int *, int , int);  
void insert_sort(int *, int, int);

int main() {

    // unsortted array 
    int array[] =  { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(array) / sizeof(array[0]); 

    insert_sort(array, 0, size - 1); 

    print_array(array, size); 

    return 0; 
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n\n"); 
}


void insert_sort(int *arr, int low, int high) {

    for (int i = 1; i <= high; i++) {
        int key = arr[i];
        int j; 
        for ( j = i - 1; j >= 0 && key < arr[j]; j--) {
            arr[j+1] = arr[j]; 
        }
        arr[j+1] = key; 
    }


}


void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}