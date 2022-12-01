#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define QUEUE_MAX_SIZE 5

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
    enqueue(&q, 10);
    enqueue(&q, 11);
    enqueue(&q, 12);
    printf("\nDequeue %d\n", dequeue(&q));
    enqueue(&q, 14);
    enqueue(&q, 15);
    enqueue(&q, 16);
    enqueue(&q, 17);
}

bool isFull(queue *q)
{
    return (q->rear == q->front + 1) || (q->rear == 0 && q->front == QUEUE_MAX_SIZE - 1);
}

bool isEmpty(queue *q)
{
    return q->front == -1;
}

int peek(queue *q)
{
    return (q->queue[q->front]);
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is Empty");
        return -1 * QUEUE_MAX_SIZE;
    }

    int temp = q->queue[q->rear];

    if (q->front == q->rear)
    {
        initialze(q);
    }

    q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;

    return (temp);
}

void enqueue(queue *q, int d)
{
    if (isFull(q))
    {
        printf("Queue Overflow");
        return;
    }
    if (q->rear == -1)
    {
        q->rear = 0;
    }

    q->front = (q->front + 1) % QUEUE_MAX_SIZE;
    q->queue[q->front] = d;
}

void initialze(queue *q)
{
    q->front = -1;
    q->rear = -1;
}