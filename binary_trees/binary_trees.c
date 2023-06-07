#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#define MAX_SIZE 100

Node* create_node(int data){
    Node* root = (Node*)malloc(sizeof(Node));
    if (root == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;        
}

Node* delete_node(Node* root, int data){
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = delete_node(root->left, data);
    } else if (data > root->data) {
        root->right = delete_node(root->right, data);
    } else {
        // Case where node has 1 or 0 children
        if (root->left == NULL) {
            // No children
            Node* tmp = root->right;
            free(root);
            return tmp;
        } else if (root->right == NULL) {
            // One child on the left
            Node* tmp = root->left;
            free(root);
            return tmp;
        }

        // Case where node has 2 children
        Node* successor = find_successor(root->right);
        root->data = successor->data;
        root->right = delete_node(root->right, successor->data);
    }

    return root;
}

Node* search_node(Node* root, int data){
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search_node(root->left, data);
    } else {
        return search_node(root->right, data);
    }
}

Node* insert_node(Node* root, int data){
    if (root == NULL) {
        root = create_node(data);
    } else if(data <= root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

Node* find_successor(Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void preorder_traversal(Node* root){
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

void inorder_traversal(Node* root){
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(Node* root){
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

void levelorder_traversal(Node* root){
    if (root == NULL) {
        return;
    }

    // create a queue for level order traversal
    Node** q = (Node**)malloc(sizeof(Node*) * MAX_SIZE);
    int front = 0;
    int rear = 0;

    // enqueue the root node
    q[rear++] = root;

    while(front < rear) {
        // dequeue the front node
        Node* curr = q[front++];
        printf("%d ", curr->data);

        // enqueue the left child if it exists
        if (curr->left != NULL) {
            q[rear++] = curr->left;
        }

        // enqueue the right child if it exists
        if (curr->right != NULL) {
            q[rear++] = curr->right;
        }
    }

    // free the memory allocated for the queue
    free(q);

}
