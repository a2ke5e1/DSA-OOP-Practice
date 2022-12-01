#include <stdio.h>
#include <stdlib.h>

void pA(int *, int *); 
void sort(int *, int *); 

void merge_sort(int *, int, int); 
int parition(int *, int, int); 
void swap(int *, int *); 
void merge(int *, int, int, int); 

void main() {
    int arr[] = {5,6,2,11,4,1,9};
    int n = sizeof(arr)/ sizeof(arr[0]); 
    sort(arr, &n); 
    printf("\n\n\n");
    pA(arr, &n);  
}

void sort(int *arr, int *n) {
    merge_sort(arr,0, *n - 1); 
}


void merge_sort(int *arr, int start, int end) {

    if (start < end) {
        int mid = (start + end) / 2; 
        merge_sort(arr, start, mid); 
        merge_sort(arr, mid + 1, end); 

        merge(arr,start, mid, end); 
    }


}

void merge(int *arr, int start, int mid, int end) {
    int i,j,k; 
    int n1 = mid - start + 1;
    int n2 = end - mid; 

    int *L = (int *)malloc(sizeof(int) * n1); 
    int *R = (int *)malloc(sizeof(int) * n2); 

    for (i = 0; i < n1; i++) {
        L[i] = arr[start + i];
    }
    for (j = 0; j < n2; j++){
        R[j] = arr[mid + 1 + j];
    }

    i = 0; 
    j = 0; 
    k = start; 
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


void pA(int *arr, int *n) {
    int i = 0; 
    for (i; i < *n; i++) {
        printf("%d ", *(arr + i)); 
    }
    printf("\n"); 
}