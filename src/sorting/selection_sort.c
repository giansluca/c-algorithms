#include "../various/utils.h"
#include <string.h>

void selection_sort_ite(int array[], int size);
void selection_sort_rec(int array[], int size, int i);
void selection_sort_ex(char array[][MAX_LEN_01], int size);

/**
 * Selection sort algorithm (iterative and recursive)
 *
 * The idea is to find the minimum value at every pass, and swap it in the
 * sorted array part (the left). Every pass i increase my starting point and i
 * find the new minimum, again swap it until the end (n-1 passes).
 *
 * Standard implementation is Iterative, it can be implemented Recursive as
 * well.
 *
 * Time Complexity: O(n^2)
 * In Place: yes
 * Stable: no
 */

void selection_sort_iteration() {
    int array[] = {4, 300, 1, 0, 8, 5, 3, 7, -4};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort_ite(array, size);

    print_int_array(array, size);
}

void selection_sort_recursion() {
    int array[] = {4, 300, 1, 0, 8, 5, 3, 7, -4, 900};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort_rec(array, size, 0);

    print_int_array(array, size);
}

void selection_sort_exercise() {
    char array[][MAX_LEN_01] = {"aa", "paper", "true", "soap", "floppy",
                                "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort_ex(array, size);

    print_string_array(array, size);
}

void selection_sort_ite(int array[], int size) {
    int i_min;

    // after size-1 passes we are guaranteed that the array is sorted.
    for (int i = 0; i < size - 1; i++) {
        // store the index of minimum value and loop every pass only over the
        // unsorted part -> ( k=i+1 ).
        i_min = i;
        for (int k = i + 1; k < size; k++) {
            if (array[k] < array[i_min]) {
                // update the new minimum value
                i_min = k;
            }
        }

        // if i have a new minimum, swap the new min in the sorted array part at
        // correct position.
        if (i_min != i) {
            swap_int_in_array(&array[i_min], &array[i]);
        }
    }
}

void selection_sort_rec(int array[], int size, int i) {
    // base case - return when start position and size are same.
    if (i == size)
        return;

    // find the minimum in the sub array.
    int i_min = i;

    for (int k = i + 1; k < size; k++) {
        if (array[k] < array[i_min]) {
            i_min = k;
        }
    }

    // if i have a new minimum, swap the new min in the sorted array part at
    // correct position.
    if (i_min != i) {
        swap_int_in_array(&array[i_min], &array[i]);
    }

    // recur for all elements except first of current subarray.
    selection_sort_rec(array, size, i + 1);
}

void selection_sort_ex(char array[][MAX_LEN_01], int size) {
    int i_min;
    // after size-1 passes we are guaranteed that the array is sorted.
    for (int i = 0; i < size - 1; i++) {
        // find the min element in the unsorted array, i initially store the
        // first element as min.
        i_min = i;
        for (int k = i + 1; k < size; k++) {
            // compare the initial min string with current string.
            if (strcmp(array[i_min], array[k]) > 0) {
                // make array[k] index as new min updating i_min.
                i_min = k;
            }
        }

        // if i have a new minimum, swap the found minimum element with the
        // first element.
        if (i_min != i) {
            swap_string_in_array(array[i], array[i_min]);
        }
    }
}
