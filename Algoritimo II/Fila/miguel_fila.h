#define MAX_SIZE 4 
#include <stdio.h>

typedef struct {
    int elements[MAX_SIZE];
    int front;
    int rear;
} Queue;


void initializeQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = 0;
}


int isEmpty(Queue *queue) {
    return queue->front == queue->rear;
}


int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}


void enqueue(Queue *queue, int element) {
    if (!isFull(queue)) {
        queue->elements[queue->rear] = element;
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    } else {
        printf("fila cheia\n");
    }
}

int dequeue(Queue *queue) {
    int element;
    if (!isEmpty(queue)) {
        element = queue->elements[queue->front]; 
        queue->front = (queue->front + 1) % MAX_SIZE; 
        return element;
    } else {
        printf("fila vazia\n");
        return -1; 
    }
}

int first(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->elements[queue->front];
    } else {
        printf("fila vazia\n");
        return -1; 
    }
}
