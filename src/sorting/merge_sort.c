#include "../various/utils.h"

void _merge(int array[], int left, int mid, int right);
int _min(int x, int y);

/**
 * Merge sort algorithm (recursive and iterative)
 * It is a divide and conquer algorithm.
 * The idea is to divide the array in two part (using recursion) until we have a
 * set of one element arrays. Then we merge them back in a sorted array.
 *
 * Standard implementation is Recursive, it can be implemented Iterative as
 * well.
 *
 * Average and Worst case Time Complexity: O(n * log n)
 * In Place: no
 * Stable: yes
 */

void merge_sort_recursive(int array[], int left, int right) {
    // base case - if left index is equal to right index, array is size one
    // element and it is ordered.
    if (left >= right)
        return;

    // calculate middle index of the array.
    int mid = (right + left) / 2;

    // recursive call to divide array in sub array until to each array is
    // size 1.
    merge_sort_recursive(array, left, mid);
    merge_sort_recursive(array, mid + 1, right);

    // merge let and right
    _merge(array, left, mid, right);
}

void merge_sort_iterative(int array[], int size) {
    int curr_size;  // for current size of sub-arrays to be merged - curr_size
                    // varies from 1 to n/2.
    int left_start; // for picking starting index of left sub-array to be merged.

    // Merge sub arrays in bottom up manner.  First merge sub arrays of
    // size 1 to create sorted sub arrays of size 2, then merge sub arrays
    // of size 2 to create sorted sub arrays of size 4, and so on.
    for (curr_size = 1; curr_size < size; curr_size = 2 * curr_size) {
        // pick starting point of different sub arrays of current size
        for (left_start = 0; left_start < size - 1;
             left_start += 2 * curr_size) {
            // find ending point of left sub-array. mid+1 is starting point of
            // right
            int mid = _min(left_start + curr_size - 1, size - 1);
            int right_end = _min(left_start + 2 * curr_size - 1, size - 1);

            // merge
            _merge(array, left_start, mid, right_end);
        }
    }
}

void _merge(int array[], int left, int mid, int right) {
    // merge two unsorted sub-array in a sorted array.
    int i, j, k;

    // calculate left and right arrays size.
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // create temp arrays.
    int left_arr[left_size];
    int right_arr[right_size];

    // copy data in the two sub arrays.
    for (i = 0; i < left_size; i++) {
        left_arr[i] = array[left + i];
    }

    for (j = 0; j < right_size; j++) {
        right_arr[j] = array[mid + j + 1];
    }

    // Merge the temp arrays back into a sorted array[l..r].
    i = 0;    // Initial index of first sub-array.
    j = 0;    // Initial index of second sub-array.
    k = left; // Initial index of merged sub-array.

    while (i < left_size && j < right_size) {
        if (left_arr[i] <= right_arr[j]) {
            array[k] = left_arr[i];
            i++;
        } else {
            array[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left_arr[], if there are any.
    while (i < left_size) {
        array[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right_arr[], if there are any.
    while (j < right_size) {
        array[k] = right_arr[j];
        j++;
        k++;
    }
}

int _min(int x, int y) {
    return (x < y) ? x : y;
}
