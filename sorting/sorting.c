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

// merge sort
void merge(int arr[], int left[], int left_size, int right[], int right_size) {
    int i = 0, j = 0, k = 0;

    while (i < left_size && j < right_size) {
        if(left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int n) {
    if (n <= 1) {
        return; // Array is already sorted
    }

    int mid = n/2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < n; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++) {
        right[i-mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}