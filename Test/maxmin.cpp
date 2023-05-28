#include <stdio.h>
int a[100], n, max, min, max1, min1, max2, min2; 
void maxmin( int i, int j) {
    if ( i == j) {
        max = min = a[i]; 
    } else if ( i == j - 1) {
        if ( a[i] >= a[j]) {
            max = a[i];
            min = a[j];  
        } else {
            max = a[j]; 
            min = a[i]; 
        }
    } else {
        int mid = ( i + j) / 2; 
        maxmin(i,mid); 
        max1 = max; 
        min1 = min; 
        
        maxmin(mid+1, j); 
        max2 = max; 
        min2 = min; 
        

        if (max1 < max2)
            max = max2;
        else
            max = max1;
        if (min1 < min2)
            min = min1;
        else
            min = min2;
    }
}
int main() {
    printf("Enter size: "); 
    scanf("%d", &n); 

    printf("Enter Elements: "); 
    for ( int i = 0; i < n; i++)
        scanf("%d", &a[i]); 

    maxmin( 0, n - 1); 

    printf("Max: %d\nMin: %d", max, min); 
    return 0; 
}