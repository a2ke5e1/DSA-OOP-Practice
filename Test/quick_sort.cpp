#include<stdio.h>

int a[100], n; 
void swap(int *a, int *b) {
    int temp = *b; 
    *b = *a; 
    *a = temp; 
}

int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1; 

    for (int j = low ; j < high; j++) {
        if ( a[j] < pivot) {
            i++; 
            int temp = a[j]; 
            a[j] = a[i]; 
            a[i] = temp; 
        }

    }
    int temp = a[high]; 
    a[high] = a[i+1]; 
    a[i+1] = a[high]; 
    return i + 1; 
}

void quick_sort(int low, int high) {
    if ( low < high) {
        int pi = partition(low, high); 
        quick_sort(low , pi - 1); 
        quick_sort(pi + 1, high); 
    }
}

int main() {
    scanf("%d", &n); 
    for (int i = 0;  i < n ; i++) 
        scanf("%d", &a[i]); 

    quick_sort(0, n - 1); 

    for (int i = 0;  i < n ; i++) 
        printf("%d ", a[i]); 
    
    return 0; 
}