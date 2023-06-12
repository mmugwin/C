#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

int main() {
    Node* root = NULL;

    // insert nodes into the binary tree
    root = insert_node(root, 50);
    root = insert_node(root, 30);
    root = insert_node(root, 20);
    root = insert_node(root, 40);
    root = insert_node(root, 203);
    root = insert_node(root, 2930);
    root = insert_node(root, 70);
    root = insert_node(root, 60);
    root = insert_node(root, 80);

    // search for a node in the binary tree
    Node* found_node = search_node(root, 40);
    if (found_node == NULL) {
        printf("Target value not found in the tree\n");
    } else {
        printf("Target found: %d\n", found_node->data);
    }

    // delete a node in the binary tree
    Node* deleted = delete_node(root, 2930);

    if (deleted) {
        printf("Target found and deleted\n");
    } else {
        printf("Target not deleted\n");
    }
 
    // display the results of various tree traversals
    // preorder
    printf("Preorder traversal:\t");
    preorder_traversal(root);
    printf("\n");

    // inorder
    printf("Inorder traversal:\t");
    inorder_traversal(root);
    printf("\n");

    // postorder
    printf("Postorder traversal:\t");
    postorder_traversal(root);
    printf("\n");

    // level order
    printf("Levelorder traversal:\t");
    levelorder_traversal(root);
    printf("\n");    

    return 0;
}