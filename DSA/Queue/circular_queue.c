#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int size, *queue, choice, front = -1, rear = -1;
void insertq(); 
void deleteq(); 
void display(); 
bool isEmpty(); 
bool isFull(); 
int main() {
    printf("Enter Size of the queue: "); 
    scanf("%d", &size); 
    queue = (int *)malloc(sizeof(int) * size); 
    printf("\nCircular Queue Implementation\n"); 
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
bool isFull() {
    return (front == rear + 1) || (front == 0 &&  rear == size - 1);
}
bool isEmpty() {
    return front == -1;
}
void insertq() {
    int x; 
    if (isFull()) {
        printf("Queue is full\n"); 
        return; 
    }
    if (front == -1) {
        front = 0; 
    }
    printf("Enter the Element: "); 
    scanf("%d", &x);
    rear =  (rear + 1 ) % size;
    queue[rear] = x;  
}
void deleteq() {
    if (isEmpty()) {
        printf("Queue is Empty\n");
        return; 
    }
    if (front == rear) {
        front = -1; 
        rear = -1;
        return;
    }
    front = (front + 1) % size;
}
void display() {
    if (isEmpty()) {
        printf("Queue is Empty.\n");
        return; 
    }
    for (int i = front; i != rear; i = (i+ 1) % size ) {
        printf("%d ", queue[i]); 
    }
    printf("%d " , queue[rear]);
    printf("\n"); 
}