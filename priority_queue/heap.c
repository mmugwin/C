#include <stdio.h>
#include "heap.h"

void initialize(PriorityQueue* pq){
    pq->size = 0;
}

int is_empty(PriorityQueue* pq){
    return pq->size == 0;
}

int is_full(PriorityQueue* pq){
    return pq->size == MAX_SIZE;
}

void swap(Element* a, Element* b){
    Element tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(PriorityQueue* pq, int index){
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size  && pq->items[left].priority < pq->items[smallest].priority) {
        smallest = left;
    }

    if(right < pq->size && pq->items[right].priority < pq->items[smallest].priority) {
        smallest =  right;
    }

    if (smallest != index) {
        swap(&pq->items[index], &pq->items[smallest]);
        heapify(pq, smallest);
    }
}

void enqueue(PriorityQueue* pq, int item, int priority){
    if (is_full(pq)) {
        printf("Priority queue is full. Cannot enqueue element.\n");
        return;
    }

    Element new_element;
    new_element.item = item;
    new_element.priority = priority;

    pq->items[pq->size] = new_element;
    int curr_idx = pq->size;
    int parent_idx = (curr_idx - 1) / 2;

    while (curr_idx > 0  && pq->items[curr_idx].priority < pq->items[parent_idx].priority) {
        swap(&pq->items[curr_idx], &pq->items[parent_idx]);
        curr_idx = parent_idx;
        parent_idx = (curr_idx - 1) / 2;
    }
    pq->size++;
}

int dequeue(PriorityQueue* pq){
    if ( is_empty(pq )) {
        printf("Priority queue is empty. Cannot dequeue element\n");
        return -1;
    }
    int highest_priority = pq->items[0].item;
    pq->items[0] = pq->items[pq->size - 1];
    pq->size--;
    heapify(pq, 0);
    return highest_priority;
}