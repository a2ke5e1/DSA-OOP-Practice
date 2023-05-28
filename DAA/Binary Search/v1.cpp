#include<stdio.h>
int a[100], n, k; 
void binarySearch(int a[], int n, int k) {
    int low = 0, high = n - 1; 
    int index = -1; 
    while ( low < high) {
        int mid = ( low + high ) /  2; 
        if (a[mid] == k) {
            index = mid; 
            break; 
        } else if ( a[mid] < k) {
            low = mid + 1; 
        } else {
            high = mid - 1; 
        }        
    }

    if ( index == -1) {
        printf("Not found"); 
    } else{

        printf("Found %d", index); 
    }
}

int main() {
    printf("Enter the size : "); 
    scanf("%d", &n); 

    printf("Enter elements: "); 
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]); 
    
    printf("Enter element to search: "); 
    scanf("%d", &k); 

    binarySearch(a, n, k); 
    return 0; 
}