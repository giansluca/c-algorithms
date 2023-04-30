#include "../various/utils.h"
#include <stdio.h>
#include <string.h>

#define K_MAX 3
void string_combinations_k(char set[], char prefix[], int k, int set_len,
                           long *count);
void string_permutation(char set[], int start, int set_len, long *count);

void combinations_k_length() {
    char set[] = "abcdefghijklmnopqrstuvwxyz";
    // char set[] = "abcd";
    int k = K_MAX;
    char prefix[K_MAX + 1] = {0};

    int set_len = (int)strlen(set);
    long count = 0;

    string_combinations_k(set, prefix, k, set_len, &count);
}

void permutation() {
    char set[] = "abc";
    int set_len = (int)strlen(set);
    long count = 0;

    string_permutation(set, 0, set_len, &count);
}

void string_combinations_k(char set[], char prefix[], int k, int set_len,
                           long *count) {
    // base condition - if k is equal to 0 then return
    if (k == 0) {
        // increase the counter to count all the permutations
        (*count)++;
        printf("%s --> %li\n", prefix, *count);
        return;
    }

    for (int i = 0; i < set_len; i++) {
        // next character of input added
        char new_prefix[K_MAX + 1] = {0};

        strcat(new_prefix, prefix);
        append(new_prefix, set[i]);
        // recursive call

        string_combinations_k(set, new_prefix, k - 1, set_len, count);
    }
}

void string_permutation(char set[], int start, int set_len, long *count) {
    // base condition - if start is equal to last element of the array then
    // print and return
    if (start == set_len - 1) {
        (*count)++;
        printf("%s --> %li\n", set, *count);
        return;
    }

    for (int i = start; i < set_len; i++) {
        swap_char_in_array(&set[start], &set[i]);
        string_permutation(set, start + 1, set_len, count);

        // backtrack
        swap_char_in_array(&set[start], &set[i]);
    }
}
