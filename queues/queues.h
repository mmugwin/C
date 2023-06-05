#ifndef QUEUES_H
#define QUEUES_H
#define MAX_SIZE 100

typedef struct
{
    int front;
    int rear;
    int items[MAX_SIZE];
} Queue;

void initialize(Queue* queue);
void enqueue(Queue* queue, int data);
int dequeue(Queue* queue);
int front(Queue* queue);
int is_empty(Queue* queue);
int is_full(Queue* queue);

#endif