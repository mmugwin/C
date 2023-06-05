#ifndef STACKS_H
#define STACKS_H
#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
} Stack;

void initialize(Stack* stack);
void push(Stack* stack, int data);
int pop(Stack* stack);
int peek(Stack* stack);
int is_full(Stack* stack);
int is_empty(Stack* stack);

#endif