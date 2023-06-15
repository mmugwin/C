#ifndef HASH_MAP_H
#define HASH_MAP_H
#define SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* buckets[SIZE];
} HashMap;

void initialize(HashMap* hm);
Node* create_node(int key, int value);
int hash(int key);
void insert(HashMap* hm, int key, int value);
void remove_key(HashMap* hm, int key);
int search(HashMap* hm, int key);

#endif