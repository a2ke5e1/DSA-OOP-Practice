#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  

void print_array(int *, int); 
void insert(int, int, int *a, int *); 

int main() {
    // clrscr(); 
    
    // Variables required
    int i, size, *a, element, pos;   

    // Takes number of elements
    printf("Enter number of elements: \n"); 
    scanf("%d", &size); 

    // Dynamically Allociates array size of twice required
    a = (int *) malloc( sizeof(int) * size * 2); 
    printf("Enter elements: \n");
    for (i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }
    
    // prints user entered numbers
    printf("You Entered \n");
    print_array(a, size);

    // Take position for number to be inserted
    printf("\n\nEnter position of element to be inserted\n"); 
    scanf("%d", &pos); 


    // Take number to be inserted
    printf("\nEnter the element to be inserted\n"); 
    scanf("%d", &element); 

    // Inserts number into the array
    insert(element, pos - 1, a, &size); 

    // prints the modified array
    printf("Result\n"); 
    print_array(a, size); 

    free(a);
    getch();
    return 0; 
}


void print_array(int *array, int size_array) {
    printf("\n");
    for (int i = 0; i < size_array; i++) {
        printf("%d ", array[i]); 
    }
}

void insert(int element, int pos, int *array, int *size_array) {
    int size = *size_array;
    for (int i  = size; i > pos ;i-- ) {
        array[i] = array[i-1]; 
    }
    array[pos] = element;
    *size_array = size + 1; 
}