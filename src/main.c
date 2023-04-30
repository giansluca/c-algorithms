
#include "searching/binary_search.h"
#include "sorting/bubble_sort.h"
#include "sorting/insertion_sort.h"
#include "sorting/merge_sort.h"
#include "sorting/quick_sort.h"
#include "sorting/selection_sort.h"
#include "various/factorial.h"
#include "various/fibonacci.h"
#include "various/string_concat.h"
#include "various/string_permutations.h"

/**
 * Notes:
 * - get the array element number : (size in bytes / size of one byte) -> int size = sizeof(array) / sizeof(array[0]);
 * - initialize a char array dynamically: memset(arrayConcat, '\0', sizeArrayConcat * sizeof(char));
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    puts("Algorithms");

    // SORTING
    /* Selection sort */
    // selection_sort_iteration();
    // selection_sort_recursion();
    // selection_sort_exercise();

    /* Bubble sort */
    // bubble_sort_iteration();
    // bubble_sort_recursion();
    // bubble_sort_exercise();

    /* Insertion sort */
    // insertion_sort_iteration();
    // insertion_sort_recursion();
    // insertion_sort_exercise();

    /* Merge sort */
    // merge_sort_recursion();
    // merge_sort_iteration();

    /* Quick sort */
    // quick_sort_recursion();
    // quick_sort_iteration();

    // SEARCHING
    /* Binary search */
    // binary_search_iteration();
    // binary_search_recursion();
    // bs_first_last_occurrence();
    // bs_count_occurrences();
    // bs_rotated_count();
    // bs_search_rotated_array();

    // VARIOUS
    /* String permutations */
    // combinations_k_length();
    // permutation();

    /* String concat */
    // string_concat_iteration();
    // string_concat_recursion();

    /* Factorial */
    // factorial_recursion();
    // factorial_iteration();

    /* Fibonacci */
    // fibonacci_recursion();
    // fibonacci_iteration();

    return 0;
}
