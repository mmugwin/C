#ifndef BINARY_TREES_H
#define BINARY_TREES_H

// struct for the node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// function prototypes
Node* create_node(int data);
Node* search_node(Node* root, int data);
Node* insert_node(Node* root, int data);
Node* find_successor(Node* node);
Node* delete_node(Node* root, int data);
void preorder_traversal(Node* root);
void inorder_traversal(Node* root);
void postorder_traversal(Node* root);
void levelorder_traversal(Node* root);

#endif