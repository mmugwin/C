#include <stdlib.h>
#include <stdio.h>
#include "linked_lists.h"

void display_list(struct Node* head) {    
    struct Node* curr = head;

    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr =  curr->next;
    }

    printf("NULL\n");
}

void delete_list(struct Node** head) {
    struct Node* curr = *head;
    struct Node* next_node;

    while(curr != NULL) {
        next_node = curr->next;
        free(curr);
        curr = next_node;
    }

    *head = NULL;
}

void insert_at_head(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insert_at_tail(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }

    struct Node* curr = *head;

    while(curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
}

struct Node* delete_node(struct Node* head, int position) {
    int curr_position = 0;
    struct Node* curr = head;
    struct Node* prev;

    if (head == NULL) {
        return head;
    }

    if (position == 0) {
        head = curr->next;
        free(curr);
        return head;    
    }

    // find position of node to be deleted
    while (curr != NULL && curr_position < position) {
        prev = curr;
        curr = curr->next;
        curr_position++;
    }

    // check if the position is out of range
    if (curr == NULL) {
        printf("Invalid position\n");
        return head;
    }

    // link the previous node to the next node, bypassing the current node
    prev->next = curr->next;

    // free memory of node to be deleted
    free(curr);
    return head;
}

struct Node* reverse_list(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next;

    while (curr != NULL) {
        // store the next node
        next = curr->next;

        // reverse the link
        curr->next = prev;

        // move pointer one position ahead
        prev = curr;
        curr = next;
    }

    // set the head pointer to the last node
    head = prev;
    return head;
}