#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

// struct for the node
struct Node {
    int data;
    struct Node* next;
};

// function prototypes
void display_list(struct Node* head);
void delete_list(struct Node** head);
void insert_at_head(struct Node** head, int data);
void insert_at_tail(struct Node** head, int data);
struct Node* reverse_list(struct Node* head);
struct Node* delete_node(struct Node* head, int position);

#endif