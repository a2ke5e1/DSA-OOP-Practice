#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int); 

void swap(int *,int *);
int partition(int *, int , int);  
void merge_sort(int *, int, int);
void merge(int *, int, int , int); 

int main() {

    // unsortted array 
    int array[] =  { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(array) / sizeof(array[0]); 

    merge_sort(array, 0, size - 1); 

    print_array(array, size); 

    return 0; 
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n\n"); 
}


void merge_sort(int *arr, int low, int high) {

    if (low < high) {
        int mid = (low + high) / 2; 
        merge_sort(arr, low, mid); 
        merge_sort(arr, mid + 1, high); 

        merge(arr,low, mid, high); 
    }


}

void merge(int *arr, int low, int mid, int high) {
    int i,j,k; 
    int n1 = mid - low + 1;
    int n2 = high - mid; 

    int *L = (int *)malloc(sizeof(int) * n1); 
    int *R = (int *)malloc(sizeof(int) * n2); 

    for (i = 0; i < n1; i++) {
        L[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = low; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }


    free(L); 
    free(R);

}


void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}