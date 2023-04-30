#include <stdbool.h>
#include <stdio.h>

int binary_search_ite(int array[], int size, int x);
int binary_search_rec(int array[], int start, int end, int x);
int bs_first_last_occur(int array[], int size, int x, bool search_first);
int bs_count_occur(int array[], int size, int x);
int bs_find_minimum(int array[], int size);
int bs_search_rotated(int array[], int size, int x);

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

void binary_search_iteration() {
    int x = 30;
    int array[] = {-30, -9, 1, 4, 6, 8, 30, 72, 453, 756};
    int size = sizeof(array) / sizeof(array[0]);
    int index_found = binary_search_ite(array, size, x);

    if (index_found == -1) {
        printf("Number: %d not found!\n", x);
    } else {
        printf("Found number: %d at index: %d\n", x, index_found);
    }
}

void binary_search_recursion() {
    int x = 72;
    int array[] = {-30, -9, 1, 4, 6, 8, 30, 72, 453, 756};
    int size = sizeof(array) / sizeof(array[0]);
    int index_found = binary_search_rec(array, 0, size - 1, x);

    if (index_found == -1) {
        printf("Number: %d not found!\n", x);
    } else {
        printf("Found number: %d at index: %d\n", x, index_found);
    }
}

void bs_first_last_occurrence() {
    int x = 8;
    int array[] = {-9, 8, 8, 8, 8, 8, 8, 72, 108, 830, 756};
    int size = sizeof(array) / sizeof(array[0]);
    bool search_first = false;
    int index_found = bs_first_last_occur(array, size - 1, x, search_first);

    if (index_found == -1) {
        printf("Number: %d not found!", x);
    } else {
        if (search_first)
            printf("Found first occurrence of number: %d at index: %d\n", x,
                   index_found);
        else
            printf("Found last occurrence of number: %d at index: %d\n", x,
                   index_found);
    }
}

void bs_count_occurrences() {
    int x = 8;
    int array[] = {-9, 8, 8, 8, 8, 8, 8, 8, 108, 830, 756};
    int size = sizeof(array) / sizeof(array[0]);
    int count = bs_count_occur(array, size, x);

    if (count == -1) {
        printf("Number: %d not found!\n", x);
    } else {
        printf("Found %d occurrences of number %d in the array\n", count, x);
    }
}

void bs_rotated_count() {
    int array[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int size = sizeof(array) / sizeof(array[0]);
    int min_index = bs_find_minimum(array, size);

    printf("The array is rotated %d times\n", min_index);
}

void bs_search_rotated_array() {
    int x = 12;
    int array[] = {11, 12, 15, 18, 2, 5, 6, 8};
    int size = sizeof(array) / sizeof(array[0]);
    int index_found = bs_search_rotated(array, size, x);

    if (index_found == -1)
        printf("Number: %d not found!\n", x);
    else
        printf("Found number: %d at index: %d\n", x, index_found);
}

int binary_search_ite(int array[], int size, int x) {
    int start = 0, end = size - 1;

    while (start <= end) {
        // calc middle index.
        // int mid = (start + end) / 2;
        int mid = start +
                  (end - start) /
                      2; // this way to avoid overflow with max integers values.
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

int binary_search_rec(int array[], int start, int end, int x) {
    // base case - if start is less than end then return
    if (start > end)
        return -1;

    // calc middle index.
    // int mid = (start + end) / 2;
    int mid =
        start + (end - start) /
                    2; // this way to avoid overflow with max integers values.

    // check if x is equal, smaller or bigger of current mid.
    if (x == array[mid]) {
        return mid; // if x is equal to mid we return the mid index.
    } else if (x < array[mid]) {
        // recursion call for the left part of the array
        return binary_search_rec(array, start, mid - 1, x);
    } else {
        return binary_search_rec(array, mid + 1, end, x);
    }
}

int bs_first_last_occur(int array[], int size, int x, bool search_first) {
    int start = 0, end = size - 1;
    int result = -1;

    while (start <= end) {
        // calc middle index.
        // int mid = (start + end) / 2;
        int mid = start +
                  (end - start) /
                      2; // this way to avoid overflow with max integers values.

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

int bs_count_occur(int array[], int size, int x) {
    int count = -1;
    int first_index = bs_first_last_occur(array, size, x, true);
    int last_index = bs_first_last_occur(array, size, x, false);

    if (first_index != -1)
        count = (last_index - first_index) + 1;

    return count;
}

/*
 * The number of rotation is equal of the number of elements before the minimum
 * element, that it is equal to the index of the minimum element.
 *
 * Find the index of the minimum element -->  number of right rotations of the
 * array. Array must be sorted and with no duplicates.
 */
int bs_find_minimum(int array[], int size) {
    int start = 0, end = size - 1;

    while (start <= end) {
        // case 1 --> if first element is smaller than last element it is the
        // minimum.
        if (array[start] <= array[end])
            return start;

        // case 2 --> if mid element id smaller than his previous and next
        // element it is the minimum.
        int mid = start + (end - start) / 2;
        int next = (mid + 1) % size;
        int prev = (mid - 1) % size;

        if (array[mid] < array[next] && array[mid] < array[prev])
            return mid;

        // case 3 --> if mid is smaller than the 'end' element, the minimum will
        // be in the left part of the array.
        else if (array[mid] < array[end])
            end = mid - 1;

        // case 4 --> if mid is bigger than the 'start' element, the minimum
        // will be in the right part of the array.
        else if (array[mid] > array[start])
            start = mid + 1;
    }

    return -1;
}

int bs_search_rotated(int array[], int size, int x) {
    int start = 0, end = size - 1;

    while (start <= end) {
        // calc middle index.
        int mid = start + (end - start) / 2;

        // case 1 -->  x is equal of current mid we have found the element
        if (x == array[mid])
            return mid;

        // case 2 --> if mid is smaller than the 'end' element, then the right
        // part of the array is sorted.
        if (array[mid] < array[end]) {
            // a) --> if x is grater than mid and smaller than end,
            // x is in the right part of the array (fix start to mid+1).
            if (x > array[mid] && x <= array[end])
                start = mid + 1;
            // b) --> go to search in the left part of the array (fix end to
            // mid-1).
            else
                end = mid - 1;
        }

        // case 3 --> if mid is bigger than the 'start' element, the left part
        // of the array is sorted.
        else if (array[mid] > array[start]) {
            // a) --> if x is grater than start end smaller than mid,
            // x is in the left part of the array (fix end to mid-1);
            if (x >= array[start] && x < array[mid])
                end = mid - 1;
            // b) --> go to search in the (unsorted) right part of the array
            // (fix start to mid+1).
            else
                start = mid + 1;
        }
    }

    return -1;
}
