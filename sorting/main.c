#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"

#define MAX_SIZE 100

void print_array(int array[], int n);
void merge_sort_main();

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
    bubble_sort(array, size);
    printf("Sorted array using bubble sort:\t");
    print_array(array, size);
    free(array);

    // merge_sort_main();
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array: ");    
    print_array(arr, n);
    merge_sort(arr, n);
    printf("Sorted array using merge sort: ");

    print_array(arr, n);
    printf("\n");
    return 0;
}

void print_array(int array[], int n) {
    for (int i =0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}