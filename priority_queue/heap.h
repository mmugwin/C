#ifndef HEAP_H
#define HEAP_H
#define MAX_SIZE 100
#include <stdint.h>

typedef struct {
    int item;
    int priority;
} Element;

typedef struct {
    Element items[MAX_SIZE];
    int size;
} PriorityQueue;

void initialize(PriorityQueue* pq);
int is_empty(PriorityQueue* pq);
int is_full(PriorityQueue* pq);
void swamp(Element* a, Element* b);
void heapify(PriorityQueue* pq, int index);
void enqueue(PriorityQueue* pq, int item, int priority);
int dequeue(PriorityQueue* pq);

#endif