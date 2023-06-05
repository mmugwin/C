#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define MAX_SIZE 100

void print_array(int array[], int n);

int main() {
    FILE *file;
    int *array;
    int size = 0;
    int num;

    // Open the file
    file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error opening file. \n");
        return 1;
    }

    // Allocate memory for the array
    array = (int *)malloc(MAX_SIZE * sizeof(int));

    // Read the integers from the file into the array
    while (fscanf(file, "%d", &num) == 1) {
        if (size >= MAX_SIZE) {
            printf("Array size limit reached. \n");
            break;
        }
        array[size++] = num;
    }

    printf("Unsorted array:\t");
    print_array(array, size);
    printf("\n");
    bubble_sort(array, size);
    printf("Sorted array:\t");
    print_array(array, size);
    printf("\n");

    free(array);

    return 0;
}

void print_array(int array[], int n) {
    for (int i =0; i < n; i++) {
        printf("%d ", array[i]);
    }
}