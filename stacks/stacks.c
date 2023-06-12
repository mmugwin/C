#include <stdio.h>
#include "stacks.h"

void initialize(Stack* stack) {
    stack->top = -1;
}

int is_empty(Stack* stack) {
    return stack->top == -1;
}

int is_full(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int peek(Stack* stack) {
    if (is_empty(stack)){
        printf("Stack is empty\n");
        return -1;
    }

    return stack->items[stack->top];
}

int pop(Stack* stack) {
    if (is_empty(stack)){
        printf("Stack is empty\n");
        return -1;
    }
    stack->top-=1;
    return stack->items[stack->top+1];
}

void push(Stack* stack, int data) {
    if (is_full(stack)) {
        printf("Stack is full. Unable to push elememt.\n");
        return;
    }

    // stack->items[++stack->top] = data; // equivalent operation
    stack->top += 1;
    stack->items[stack->top] = data;
}