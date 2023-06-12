#include <stdio.h>
#include <stdlib.h>
#include "queues.h"

int main() {
    Queue q;
    initialize(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("Front element: %d\n", front(&q));

    printf("Elements: ");
    while (!is_empty(&q)) {
        printf("%d ", dequeue(&q));
    }
    printf("\n");    

    return 0;
}