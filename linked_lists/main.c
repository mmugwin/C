#include <stdio.h>
#include "linked_lists.h"

int main() {
    struct Node* head = NULL; // initialize an empty list

    // insert some data into the list
    insert_at_head(&head, 10);
    insert_at_tail(&head, 93);
    insert_at_head(&head, 1000);
    insert_at_tail(&head, 93);
    insert_at_head(&head, 46);
    insert_at_tail(&head, 56);
    insert_at_head(&head, 569);
    insert_at_tail(&head, 0);

    printf("Linked List: ");
    display_list(head);

    head = reverse_list(head);
    printf("Reversed List: ");
    display_list(head);

    head = delete_node(head, 4);
    printf("List after deleting the 4th node: ");
    display_list(head);

    delete_list(&head);
    printf("List after deleting: ");
    display_list(head);

    return 0;
}