#include <stdio.h>
#include <stdlib.h>
int size, *queue, choice, front = -1, rear = -1;
void insertq(); 
void deleteq(); 
void display(); 
int main() {
    printf("Enter Size of the queue: "); 
    scanf("%d", &size); 
    queue = (int *)malloc(sizeof(int) * size); 
    printf("\nQueue Implementation"); 
    printf("\n====================\n");
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n"); 
    do {
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
        switch (choice) {
            case 1: {
                insertq(); 
                break;
            }
            case 2: {
                deleteq(); 
                break; 
            }
            case 3: {
                display(); 
                break;
            }
            case 4: exit(1); 
            default: {
                printf("Invalid Choice");
            }
        }
    } while ( choice != 4);
    free(queue); 
    return 0; 
}
void insertq() {
    int x; 
    if (rear >= size - 1) {
        printf("Queue is full\n"); 
        return; 
    }
    if (front == -1 && rear == -1) {
        front++; 
    }
    printf("Enter the Element: "); 
    scanf("%d", &x);
    queue[++rear] = x;  
}
void deleteq() {
    if (front >= size) {
        printf("Queue is Clear\n");
        return; 
    }
    front++;
}
void display() {
    if (rear == -1 || front == size) {
        printf("Queue is Empty.\n");
        return; 
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]); 
    }
    printf("\n"); 
}