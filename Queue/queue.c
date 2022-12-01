#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 10

typedef struct queue
{
    int queue[QUEUE_MAX_SIZE];
    int rear;
    int front;
} queue;

void enqueue(queue *, int);
int dequeue(queue *);
int peek(queue *);
void initialze(queue *);
bool isFull(queue *);
bool isEmpty(queue *);


void main()
{
    queue q; 
    initialze(&q); 

    printf("\n%d\n", dequeue(&q));

    enqueue(&q, 5); 
    enqueue(&q, 6); 
    enqueue(&q, 7); 

    printf("\n%d\n", peek(&q)); 

    enqueue(&q, 8); 
    enqueue(&q, 9); 
    enqueue(&q, 11); 
    enqueue(&q, 76); 
    enqueue(&q, 72); 
    enqueue(&q, 74); 
    enqueue(&q, 89);
    enqueue(&q, 150); 

    printf("\n%d\n", dequeue(&q)); 

}

bool isFull(queue *q)
{
    return q->front >= QUEUE_MAX_SIZE - 1;
}

bool isEmpty(queue *q)
{
    return (q->rear == -1 && q->front == - 1);
}

int peek(queue *q) 
{
    return ( q->queue[q->front]); 
}

int dequeue(queue *q)
{
    if (isEmpty(q)) {
        printf("Queue is Empty"); 
        return -1 * QUEUE_MAX_SIZE;
    }
    return (q->queue[q->rear++]); 
}

void enqueue(queue *q, int d)
{
    if (isFull(q)) {
        printf("Queue Overflow"); 
        return;
    }
    if (isEmpty(q)) {
        q->rear++; 
    }
    q->queue[++q->front] = d; 
}

void initialze(queue *q) 
{
    q->front = -1; 
    q->rear = -1; 
}