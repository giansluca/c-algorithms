#include <stdbool.h>
#include <stdio.h>

/**
 * Binary search algorithm (iterative and recursive)
 * For binary search the array must be sorted
 * it is a search that reduce the the search space into half respect linear
 * search "O(n)" only because the array is sorted. The idea is to find the
 * middle index of the array and check if the number we are searching is equal
 * or bigger or smaller of it. If it is bigger we continue with the same method
 * in the right part of the array until we will find it. If it is smaller we do
 * the same thing but in the left part of the array.
 *
 * Implementation can be Iterative o Recursive
 *
 * Worst and Average case Time complexity: O(log n)
 */

int binary_search_iterative(int array[], int size, int x) {
    int start = 0, end = size - 1;

    while (start <= end) {
        // calc middle index.
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2; // this way to avoid overflow with max integers values.

        // check if x is equal, smaller or bigger of current mid.
        if (x == array[mid]) {
            // if yes we return the mid index.
            return mid;
        } else if (x < array[mid]) {
            // x if before mid, move end to left part of the array.
            end = mid - 1;
        } else {
            // x is after mid move start to right part of the array.
            start = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursive(int array[], int start, int end, int x) {
    // base case - if start is less than end then return
    if (start > end)
        return -1;

    // calc middle index.
    // int mid = (start + end) / 2;
    int mid = start + (end - start) / 2; // this way to avoid overflow with max integers values.

    // check if x is equal, smaller or bigger of current mid.
    if (x == array[mid]) {
        return mid; // if x is equal to mid we return the mid index.
    } else if (x < array[mid]) {
        // recursion call for the left part of the array
        return binary_search_recursive(array, start, mid - 1, x);
    } else {
        return binary_search_recursive(array, mid + 1, end, x);
    }
}

int binary_search_first_or_last_occurrence(int array[], int size, int x, bool search_first) {
    int start = 0, end = size - 1;
    int result = -1;

    while (start <= end) {
        // calc middle index.
        // int mid = (start + end) / 2;
        int mid = start + (end - start) / 2; // this way to avoid overflow with max integers values.

        if (x == array[mid]) {
            /*
             * when i find x:
             * instead to exit i store the value in a variable and i continue to
             * search toward left or right to check if there are other values.
             */
            result = mid;
            if (search_first)
                /* first occurrence */
                end = mid - 1;
            else
                /* last occurrence */
                start = mid + 1;
        } else if (x < array[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return result;
}

int binary_search_count_occurrences(int array[], int size, int x) {
    int count = 0;
    int first_index = binary_search_first_or_last_occurrence(array, size, x, true);
    int last_index = binary_search_first_or_last_occurrence(array, size, x, false);

    if (first_index != -1)
        count = (last_index - first_index) + 1;

    return count;
}
