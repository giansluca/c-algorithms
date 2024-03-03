#include "../various/utils.h"
#include <stdbool.h>
#include <string.h>

/**
 * Bubble sort algorithm (iterative and recursive)
 *
 * The idea is to move in every pass the max element to the end of the array,
 * building in that way a sorted part (right) and unsorted part (left).
 * For each pass i will loop only over the unsorted part, and a flag to check if
 * there have been a swap, will tell me if the array is already sorted.
 *
 * Standard implementation is Iterative, it can be implemented Recursive as
 * well.
 *
 * Worst and Average case Time Complexity: O(n^2)
 * Best case Time Complexity: O(n)
 * In Place: yes
 * Stable: yes
 */

void bubble_sort_iterative(int array[], int size) {
    bool flag;

    // after size-1 passes we are guaranteed that the array is sorted.
    for (int i = 0; i < size - 1; i++) {
        flag = false;
        // loop every pass only over the unsorted part -> ( i < size-k-1 ).
        for (int k = 0; k < size - i - 1; k++) {
            if (array[k] > array[k + 1]) {
                // if next element is smaller then swap.
                swap_int_in_array(&array[k], &array[k + 1]);
                flag = true;
            }
        }

        // improvement: if there have been no swaps the array is already sorted,
        // so i exit.
        if (!flag) {
            break;
        }
    }
}

void bubble_sort_recursive(int array[], int size) {
    // base case - return when the size is equal to 1, the array is sorted.
    if (size == 1)
        return;

    bool flag = false;
    // one pass of normal bubble sort, to fix the last element (max value) of
    // current sub-array.
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            // if next element is smaller then swap.
            swap_int_in_array(&array[i], &array[i + 1]);
            flag = true;
        }
    }

    // improvement: if there have been no swaps the array is already sorted, so
    // i return.
    if (!flag) {
        return;
    }

    // recur for all elements except last of current sub-array.
    bubble_sort_recursive(array, size - 1);
}

void bubble_sort_string_array(char *array[], int size) {
    bool flag;

    // after size-1 passes we are guaranteed that the array is sorted.
    for (int i = 0; i < size; i++) {
        flag = false;
        // loop every pass only over the unsorted part -> ( i < size-k-1 ).
        for (int k = 0; k < size - i - 1; k++) {
            // compare the actual string with the next, if the left string
            // bigger then swap.
            if (strcmp(array[k], array[k + 1]) > 0) {
                swap_string_in_array(&array[k], &array[k + 1]);
                flag = true;
            }
        }

        // if there have been no swaps the array is already sorted, so i exit.
        if (!flag) {
            break;
        }
    }
}
