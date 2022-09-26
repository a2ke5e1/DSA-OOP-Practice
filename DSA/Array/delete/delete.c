#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  

void print_array(int *, int); 
void delete(int, int *a, int *); 

int main() {
    // clrscr(); 
    
    // Variables required
    int i, size, *a, pos;   

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

    // Take position for number to be deleted
    printf("\n\nEnter position of element to be deleted\n"); 
    scanf("%d", &pos); 

    // delete number into the array
    delete(pos - 1, a, &size); 

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

void delete(int pos, int *array, int *size_array) {
    int size = *size_array;
    for (int i  = pos; i < size ;i++) {
        array[i] = array[i+1]; 
    }
    *size_array = size - 1; 
}