#include <stdbool.h>

#ifndef ALGORITHMS_BINARY_SEARCH_H
#define ALGORITHMS_BINARY_SEARCH_H

int binary_search_iterative(int array[], int size, int x);
int binary_search_recursive(int array[], int start, int end, int x);
int binary_search_first_or_last_occurrence(int array[], int size, int x, bool search_first);
int binary_search_count_occurrences(int array[], int size, int x);

#endif // ALGORITHMS_BINARY_SEARCH_H
