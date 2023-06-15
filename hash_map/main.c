#include <stdio.h>
#include <stdlib.h>
#include "hash_map.h"

int main() {
    HashMap hm;
    initialize(&hm);

    insert(&hm, 1, 10);
    insert(&hm, 11, 20);
    insert(&hm, 21, 30);

    printf("Value for key 1: %d\n", search(&hm, 1));
    printf("Value for key 11: %d\n", search(&hm, 11));

    remove_key(&hm, 11);

    printf("Value for key 11 after deletion: %d\n", search(&hm, 11));

    return 0;
}