#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


void bubble_sort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // swap arr[j] and arr[j+1]
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }   
}

// // quick sort
// void swap(int* a, int* b);
// int partition(int arr[], int low, int high);
// void quick_sort(int arr[], int low, int high);

// // merge sort
// void merge(int arr[], int left[], int left_size, int right[], int right_size);
// void merge_sort(int arr[], int n);