#ifndef SORTING_H
#define SORTING_H

void bubble_sort(int arr[], int n);

// quick sort
void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);

// merge sort
void merge(int arr[], int left[], int left_size, int right[], int right_size);
void merge_sort(int arr[], int n);

#endif