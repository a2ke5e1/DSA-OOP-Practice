#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int); 
int *merge(int *, int *, int, int);
int *create_array(int);
void populate_array(int *, char *, int);  
int get_size(char *); 

int main() {

    int size_a, size_b, size_c, *a, *b, *c;

    size_a = get_size("first"); 
    a = create_array(size_a); 
    populate_array(a, "first", size_a); 


    size_b = get_size("second"); 
    b = create_array(size_b); 
    populate_array(b, "second", size_b); 


    print_array(a, size_a); 
    print_array(b, size_b);

    c = merge(a,b,size_a,size_b); 

    printf("\n\nMereged Array\n"); 
    print_array(c, size_a + size_b); 

    free(a); 
    free(b); 
    free(c); 
    return 0;
}

int *merge(int *a, int *b, int size_a, int size_b) {
    int *c, size_c; 
    
    size_c = size_a + size_b; 
    c = create_array(size_c); 

    int i = 0, j = 0, k = 0;
    while (k < size_c) {

        if ( a[i] <= b[j]) {
            c[k] = a[i]; 
            k++; 
            i++; 
        }

        if (b[j] <= a[i] ) {
            c[k] = b[j]; 
            k++; 
            j++; 
        }   
    }

    return c; 
}

int get_size(char *type) {
    int size;
    printf("Enter Size of the %s array\n", type); 
    scanf("%d", &size); 
    return size; 

}

int *create_array(int size) {
    return (int*)malloc(sizeof(int) * size);
}

void populate_array(int *array, char *type, int size) {
    int i; 
    printf("Enter element in the %s array\n", type); 
    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]); 
    }
}

void print_array(int *array, int size_array) {
    printf("\n");
    for (int i = 0; i < size_array; i++) {
        printf("%d ", array[i]); 
    }
}