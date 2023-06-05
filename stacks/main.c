#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

int main() {
    Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    printf("Elements: ");
    while (!is_empty(&stack)) {
        printf("%d ", pop(&stack));
    }
    printf("\n");

    return 0;
}