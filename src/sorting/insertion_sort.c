#include "../various/utils.h"

/**
 * Insertion sort algorithm (iterative and recursive)
 *
 * The Idea is to divide the array in two subset, one sorted part and the other
 * unsorted. Then picking elements from the unsorted part of the array one by
 * one and inserting them in the correct position in the sorted part of the
 * array (the left). Initially we set the first element of the array (index = 0)
 * in the sorted part, and we start picking from the unsorted part the second
 * element, and so on ... To insert the element in the position i will shift on
 * the right all the elements bigger than the one i'm inserting, and then i will
 * fill the empty space with my element. Even if time complexity is equal to
 * Bubble and Selection sort, in a practical scenario the numbers of comparisons
 * and shifts are less.
 *
 * Standard implementation is Iterative, it can be implemented Recursive as
 * well.
 *
 * Worst and Average Case Time Complexity: O(n^2)
 * Best Case Time Complexity: O(n)
 * In Place: Yes
 * Stable: Yes
 */

void insertion_sort_iterative(int array[], int size) {
    int value, hole;

    for (int i = 1; i < size; i++) {
        // store the element i'm inserting in a temporary variable.
        value = array[i];

        // set the hole to the first element of the sorted array part.
        hole = i;
        while (hole > 0 && array[hole - 1] > value) {
            // shift all the value bigger than 'value' to the right.
            array[hole] = array[hole - 1];
            hole = hole - 1;
        }

        // insert the element int the correct hole position, created after the
        // shifting.
        array[hole] = value;
    }
}

void insertion_sort_recursive(int array[], int size) {
    // base condition - if size is less than 1 return
    if (size <= 1)
        return;

    // recur for the size-1 times
    insertion_sort_recursive(array, size - 1);

    // i'm using size as a index here, at last recursion it will be = 2, size-1
    // will pointing to the first element the one i want to start the
    // comparision and insertion.
    int value = array[size - 1];
    int hole = size - 1;
    while (hole > 0 && array[hole - 1] > value) {
        // shift all the value bigger than 'value' to the right.
        array[hole] = array[hole - 1];
        hole = hole - 1;
    }

    // inset the value.
    array[hole] = value;
}

/*
 * Array of int sorting nearest to given number (iterative)
 */
void insertion_sort_nearest_to_given_number(int array[], int size, int number) {
    int value, hole;
    // loop over the number of elements except the first.
    for (int i = 1; i < size; i++) {
        // calculate the distance between the actual array number and the given
        // number.
        int distance = numbers_distance(array[i], number);
        // store the actual array element
        value = array[i];
        // set the hole to the actual index element of the sorted array part.
        hole = i;

        // loop for elements shift based on the number distance order - calling
        // function: numbersDistance.
        while (hole > 0 &&
               numbers_distance(array[hole - 1], number) > distance) {
            // shift.
            array[hole] = array[hole - 1];
            hole = hole - 1;
        }

        // insert the element int the correct hole position
        array[hole] = value;
    }
}
