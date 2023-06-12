#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    PriorityQueue pq;
    initialize(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 0, 1);
    enqueue(&pq, 1000, 3);

    printf("Dequeued element: %d\n", dequeue(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));
    printf("Dequeued element: %d\n", dequeue(&pq));

    return 0;
}