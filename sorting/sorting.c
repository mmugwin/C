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

// quick sort
void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];      // choose the last element as the pivot
    int i = low - 1;            // index of the smaller element

    for (int j = low; j <= high - 1; j++) {
        // if the current element is smaller than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }    
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quick_sort(int arr[], int low, int high){
    if (low < high) {
        int partition_idx = partition(arr, low, high); // partitioning index
        quick_sort(arr, low, partition_idx - 1);
        quick_sort(arr, partition_idx + 1, high);
    }
}


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