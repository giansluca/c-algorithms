#include "../various/utils.h"

int _partition(int array[], int start, int end);

/**
 * Quick sort algorithm (recursive and iterative)
 * It is a divide and conquer algorithm.
 * The idea is to select an element of the array (pivot) and rearrange the array
 * such that all the element smaller than the pivot are to the left of it and
 * all element greater then the pivot are on his right.
 * This process is called partitioning. Then same process using recursion for
 * the su arrays until we have element of size one.
 *
 * Standard implementation is Recursive, it can be implemented Iterative as
 * well.
 *
 * Average case Time Complexity: O(n * log n)
 * Worst case Time Complexity: O(n^2)
 * In Place: yes
 * Stable: no
 */

void quick_sort_recursive(int array[], int start, int end) {
    // base case - if the sub array is one element then exit recursion.
    if (start >= end)
        return;

    // partition the sub array.
    int p_index = _partition(array, start, end);

    // recursive call.
    quick_sort_recursive(array, start, p_index - 1);
    quick_sort_recursive(array, p_index + 1, end);
}

void quick_sort_iterative(int array[], int start, int end) {
    // Create an auxiliary stack.
    int stack[end - start + 1];
    // initialize top of stack.
    int top = -1;
    // push initial values of start and end to stack
    stack[++top] = start;
    stack[++top] = end;

    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop end and start
        end = stack[top--];
        start = stack[top--];
        // partition the sub array.
        int pIndex = _partition(array, start, end);

        // If there are elements on left side of pivot,
        // then push left side to stack
        if (pIndex - 1 > start) {
            stack[++top] = start;
            stack[++top] = pIndex - 1;
        }

        // If there are elements on right side of pivot,
        // then push right side to stack
        if (pIndex + 1 < end) {
            stack[++top] = pIndex + 1;
            stack[++top] = end;
        }
    }
}

int _partition(int array[], int start, int end) {
    // choose  the last element as the pivot element.
    int pivot = array[end];
    int p_index = start;

    // loop over the array (minus the pivot) for partitioning.
    // put all the element less than the pivot to the left of p_index.
    for (int i = start; i < end; i++) {
        if (array[i] <= pivot) {
            // swap
            swap_int_in_array(&array[i], &array[p_index]);
            p_index++;
        }
    }

    // final step is to swap the pivot with the element at the partition index
    swap_int_in_array(&array[p_index], &array[end]);

    return p_index;
}
