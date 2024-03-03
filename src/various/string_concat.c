#include "../various/utils.h"
#include <string.h>

void string_concat_ite(char array[][STRING_LENGTH], int size, char array_concat[]);
void string_concat_rec(char array[][STRING_LENGTH], int size, char array_concat[],
                       int index);

void string_concat_iteration() {
    char array[][STRING_LENGTH] = {"aa", "xx", "paper", "true", "soap",
                                   "22", "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);

    int size_array_concat = (size * STRING_LENGTH) + size;
    char array_concat[size_array_concat];

    string_concat_ite(array, size, array_concat);
    print_char_array(array_concat);
}

void string_concat_recursion() {
    char array[][STRING_LENGTH] = {"aa", "xx", "paper", "true", "soap",
                                   "22", "flower", "gigi", "zzz", "hhh"};
    int size = sizeof(array) / sizeof(array[0]);

    int size_array_concat = (size * STRING_LENGTH) + size;
    char array_concat[size_array_concat];

    string_concat_rec(array, size, array_concat, 0);
    print_char_array(array_concat);
}

void string_concat_ite(char array[][STRING_LENGTH], int size,
                       char array_concat[]) {
    for (int i = 0; i < size; i++) {
        if (i == 0) {
            strcat(array_concat, array[i]);
        } else {
            strcat(array_concat, ",");
            strcat(array_concat, array[i]);
        }
    }

    strcat(array_concat, "\0");
}

void string_concat_rec(char array[][STRING_LENGTH], int size, char array_concat[],
                       int index) {
    // base case - if index is equal to size then return
    // (here i'm checking the opposite and put the recursive call inside the
    // 'if' condition)
    if (index < size) {
        if (index == 0) {
            strcat(array_concat, array[index]);
        } else {
            strcat(array_concat, ",");
            strcat(array_concat, array[index]);
        }

        string_concat_rec(array, size, array_concat, index + 1);
    }

    return;
}
