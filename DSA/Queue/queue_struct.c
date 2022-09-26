#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int size, *items, front, rear;
} queue; 

void insertq(queue *); 
void deleteq(queue *); 
void display(queue *); 
int main() {
    int choice; 

    queue *q = (queue *)malloc(sizeof(queue)); 

    q->front = -1; 
    q->rear = -1;

    printf("Enter Size of the queue: "); 
    scanf("%d", &q->size); 


    q->items = (int *)malloc(sizeof(int) * q->size); 
    
    
    printf("\nQueue Implementation\n"); 
    printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n\n"); 
    do {
        printf("\nEnter your choice: "); 
        scanf("%d", &choice); 
    
        switch (choice) {
            case 1: {
                insertq(q); 
                break;
            }
            case 2: {
                deleteq(q); 
                break; 
            }
            case 3: {
                display(q); 
                break;
            }
            case 4: exit(1); 
            default: {
                printf("Invalid Choice");
            }
        }
    } while ( choice != 4);
    free(q); 
    return 0; 
}
void insertq(queue *q) {
    int x; 
    if (q->rear == q->size - 1) {
        printf("Queue is full\n"); 
        return; 
    }
    if (q->front == -1) {
        q->front++; 
    }
    printf("Enter the Element: "); 
    scanf("%d", &x);
    q->rear++; 
    q->items[q->rear] = x;  
}
void deleteq(queue *q) {
    if (q->front >= q->size) {
        printf("Queue is Clear\n");
        return; 
    }
    q->front++;
}
void display(queue  *q) {
    if (q->rear == -1 || q->front == q->size) {
        printf("Queue is Empty.\n");
        return; 
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]); 
    }
    printf("\n"); 
}