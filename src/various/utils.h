#ifndef ALGORITHMS_UTILS_H
#define ALGORITHMS_UTILS_H

#define MAX_LEN_01 100

void print_int_array(int array[], int size);
void print_char_array(char array[]);
void print_string_array(char array[][MAX_LEN_01], int size);
void swap_int_in_array(int *a, int *b);
void swap_char_in_array(char *a, char *b);
void swap_string_in_array(char *a, char *b);
int numbers_distance(int num1, int num2);
void append(char array[], char c);

#endif // ALGORITHMS_UTILS_H
