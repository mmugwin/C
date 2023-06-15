#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"

void initialize(HashMap* hm) {
    for (int i =0; i < SIZE; i++) {
        hm->buckets[i] = NULL;
    }
}

int hash(int key) {
    /*
        Simple hashing function for now
        More complicated functions used in practice to avoid collisions
    */
    return key % SIZE;
}

Node* create_node(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->next = NULL;
    return node;
}


void insert(HashMap* hm, int key, int value) {
    int index = hash(key);

    Node* new_node = create_node(key, value);

    if(hm->buckets[index] == NULL) {
        hm->buckets[index] = new_node;
    } else {
        Node* curr = hm->buckets[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

int search(HashMap* hm, int key) {
    int index = hash(key);

    Node* curr = hm->buckets[index];

    while(curr != NULL) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }

    return -1; // Key not found
}

void remove_key(HashMap* hm, int key) {
    int index = hash(key);

    Node* prev = NULL;
    Node* curr = hm->buckets[index];

    while(curr != NULL && curr->key != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Key not found. Cannot delete\n");
        return;
    }

    if (prev == NULL) {
        hm->buckets[index] = curr->next;
    } else {
        prev->next = curr->next;
    }

    free(curr);
}
