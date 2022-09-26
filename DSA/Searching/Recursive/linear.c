#include <stdio.h>
#include <stdlib.h>

void print_array(int *, int); 
int find(int, int, int*, int);
int *create_array(int);
void populate_array(int *, char *, int);  
int get_size(char *); 

int main() {

    int size_a, *a, pos, num; 

    size_a = get_size(""); 
    a = create_array(size_a); 
    populate_array(a, "", size_a); 

    printf("\nEnter Number to find\n"); 
    scanf("%d", &num); 

    print_array(a, size_a);
    
    pos = find(num, 0, a, size_a); 
    pos == -1 ? printf("\nNot Found") :  printf("\nPosition :%d", pos); 

    free(a);
    return 0;
}

int find(int element, int pos, int *a, int size) {

    if ( pos == size) {
        return -1; 
    }

    if (element == a[pos]) {
        return pos + 1;
    }

    return find(element, pos+1, a, size); 

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