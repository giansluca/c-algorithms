#include "string_concat.h"
#include "../various/utils.h"
#include <stdlib.h>
#include <string.h>

char *string_concat_iterative(char *array[], int size, int size_array_concat) {
    char *array_concat = (char *)malloc(size_array_concat);

    for (int i = 0; i < size; i++) {
        if (i == 0) {
            strcat(array_concat, array[i]);
        } else {
            strcat(array_concat, ",");
            strcat(array_concat, array[i]);
        }
    }

    strcat(array_concat, "\0");
    return array_concat;
}

void string_concat_recursive(char *array[], int size, char array_concat[], int index) {
    // base case - if index is equal to size then return
    // here i'm checking the opposite and put the recursive call inside the 'if' condition
    if (index < size) {
        if (index == 0) {
            strcat(array_concat, array[index]);
        } else {
            strcat(array_concat, ",");
            strcat(array_concat, array[index]);
        }

        string_concat_recursive(array, size, array_concat, index + 1);
    }

    return;
}

int calculate_concat_array_size(char *array[], int size) {
    int size_array_concat = 0;
    for (int i = 0; i < size; i++) {
        char *string = array[i];

        int j = 0;
        while (*(string + j) != '\0') {
            size_array_concat++;
            j++;
        }
    }

    return size_array_concat + size; // adding 'size' is the space for commas and '\0' , commas size = (size - 1)
}
