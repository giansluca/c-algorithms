#include "utils.h"
#include <stdio.h>
#include <string.h>

void print_int_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", array[i]);
    }
}

void print_char_array(char array[]) {
    int i = 0;
    while (array[i] != '\0') {
        printf("%c", array[i]);
        i++;
    }
    puts("\n");
}

void print_string_array(char *array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", array[i]);
    }
}

void swap_int_in_array(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char_in_array(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swap_string_in_array(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

int numbers_distance(int num1, int num2) {
    return num1 > num2 ? num1 - num2 : num2 - num1;
}

void append(char array[], char c) {
    int len = (int)strlen(array);

    array[len] = c;
    array[len + 1] = '\0';
}
