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

    printf("Unsorted array\t(bubble sort):\t");
    print_array(array, size);
    bubble_sort(array, size);

    printf("Sorted array\t(bubble sort):\t");
    print_array(array, size);
    free(array);


    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array\t(merge sort):\t");    
    print_array(arr, n);
    merge_sort(arr, n);
    printf("Sorted array\t(merge sort):\t");

    print_array(arr, n);

    int arr2[] = {6, 45, 53, 12, 22, 101, 90, -20, 129, 244, 0, -13};
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("Unsorted array\t(quick sort):\t");    
    print_array(arr2, n);
    quick_sort(arr2, 0, n-1);
    printf("Sorted array\t(quick sort):\t");

    print_array(arr2, n);

    return 0;
}

void print_array(int array[], int n) {
    for (int i =0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}