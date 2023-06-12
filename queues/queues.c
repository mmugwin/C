#include <stdio.h>
#include "queues.h"

void initialize(Queue* queue){
    queue->front = -1;
    queue->rear = -1;
}

void enqueue(Queue* queue, int data){
    if (is_full(queue)) {
        printf("Queue is full! Cannot enqueue.\n");
        return;
    }

    if (is_empty(queue)) {
        queue->front = 0;
    }
    // queue->items[++queue->rear] = item; // equivalent syntax
    queue->rear += 1;
    queue->items[queue->rear] = data;
}

int dequeue(Queue* queue){
    if (is_empty(queue)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    }
    int data = queue->items[queue->front];
    if (queue->front == queue->rear) {
        // reset the queue when the last element is dequeued
        initialize(queue);
    } else {
        queue->front += 1;
    }
    return data;
}

int front(Queue* queue){
    if (is_empty(queue)) {
        printf("The queue is empty. No front element!");
        return -1;
    }
    return queue->items[queue->front];
}

int is_empty(Queue* queue){
    return queue->front == -1 && queue->rear == -1;
}

int is_full(Queue* queue){
    return queue->rear == MAX_SIZE - 1;
}
