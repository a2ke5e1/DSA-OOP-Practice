#include<stdio.h>
int a[100], n;


void merge(int low, int mid, int high) {
    int n1 = mid - low + 1; 
    int n2 = high - mid; 

    int l[n1], r[n2]; 
    for (int i = 0; i < n1; i++) 
        l[i] = a[low + i]; 

    for (int j = 0; j < n2; j++) 
        r[j] = a[mid + j + 1]; 

    int i = 0, j = 0, k = low; 
    while ( i < n1 && j  < n2) {
        if ( l[i] < r[j]) {
            a[k] = l[i]; 
            i++; 
        } else {
            a[k] = r[j]; 
            j++; 
        }
        k++; 
    }

    while ( i < n1) {
        a[k] = l[i]; 
        k++; 
        i++; 
}
    while ( j < n2) {
        a[k] = r[j]; 
        k++; 
        j++; 
    }

        

}


void merge_sort(int low, int high) {
    if (low  < high) {
        int mid = (low + high) /  2; 
        merge_sort(low, mid); 
        merge_sort(mid + 1, high); 
        merge(low, mid, high); 
    }
}


int main() {
    scanf("%d", &n); 
    for (int i = 0;  i < n ; i++) 
        scanf("%d", &a[i]); 

    merge_sort(0, n - 1); 

    for (int i = 0;  i < n ; i++) 
        printf("%d ", a[i]); 
    
    return 0; 
}