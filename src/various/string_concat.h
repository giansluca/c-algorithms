#ifndef ALGORITHMS_STRING_CONCAT_H
#define ALGORITHMS_STRING_CONCAT_H

char *string_concat_iterative(char *array[], int size, int size_array_concat);
void string_concat_recursive(char *array[], int size, char array_concat[], int index);
int calculate_concat_array_size(char *array[], int size);

#endif // ALGORITHMS_STRING_CONCAT_H
