#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>


int main() {

    int *arr, i, size, ele; 
    
    printf("Enter size of the array: \n"); 
    scanf("%d", &size); 

    arr = (int *)malloc(sizeof(int) * size); 

    printf("Enter the elements in the array:\n"); 
    for (i = 0; i< size; i++) {
        scanf("%d", &arr[i]); 
    }
    
    printf("Enter number to find in array:\n"); 
    scanf("%d", &ele); 
    
    for (i = 0; i < size; i++) {
        if ( ele == arr[i]) {
            printf("Found '%d' at index %d.\n", ele, i+1); 
            break;
        }
    }

    free(arr); 
    return 0; 
}