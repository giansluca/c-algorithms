#include "../../src/various/factorial.h"
#include "../../src/various/fibonacci.h"
#include "../../src/various/string_concat.h"
#include "../../src/various/string_permutations.h"
#include "../../src/various/utils.h"
#include "../unity/unity.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// String concat
void it_should_concat_string_iterative() {
    // given
    char *array[] = {"aa", "xx", "paper", "true", "soap", "22", "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);
    int size_array_concat = calculate_concat_array_size(array, size);

    // when
    char *array_concat = string_concat_iterative(array, size, size_array_concat);

    // then
    char *expected = "aa,xx,paper,true,soap,22,flower,gigi,zzz,aaa";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, array_concat, size_array_concat);
}

void it_should_concat_string_recursive() {
    // given
    char *array[] = {"aa", "xx", "paper", "true", "soap", "22", "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);

    int size_array_concat = calculate_concat_array_size(array, size);
    char *array_concat = (char *)malloc(size_array_concat);

    // when
    string_concat_recursive(array, size, array_concat, 0);

    // then
    char *expected = "aa,xx,paper,true,soap,22,flower,gigi,zzz,aaa";
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expected, array_concat, size_array_concat);
}

// String Permutation
void it_should_test_string_permutations() {
    // given
    char set[] = "abc";
    int set_len = (int)strlen(set);
    long count = 0;

    // when - then
    string_permutation(set, 0, set_len, &count);
}

void it_should_test_string_combinations_k() {
    // given
    // char set[] = "abcdefghijklmnopqrstuvwxyz";
    char set[] = "abcd";

    int k = K_MAX;
    char prefix[K_MAX + 1] = {0};
    int set_len = (int)strlen(set);
    long count = 0;

    // when - then
    string_combinations_k(set, prefix, k, set_len, &count);
}

// Factorial
void it_should_calculate_factorial_iterative() {
    // given
    int number = 5;

    // when
    int factorial = factorial_iterative(number);

    // then
    TEST_ASSERT_EQUAL_INT(120, factorial);
}

void it_should_calculate_factorial_recursive() {
    // given
    int number = 6;

    // when
    int factorial = factorial_recursive(number);

    // then
    TEST_ASSERT_EQUAL_INT(720, factorial);
}

// Fibonacci
void it_should_calculate_fibonacci_iterative() {
    // given
    int number = 9;

    // when
    int fib = fibonacci_iterative(number);

    // then
    TEST_ASSERT_EQUAL_INT(34, fib);
}

void it_should_calculate_fibonacci_recursive() {
    // given
    int number = 15;

    // when
    int fib = fibonacci_recursive(number);

    // then
    TEST_ASSERT_EQUAL_INT(610, fib);
}

int main() {
    UNITY_BEGIN();

    // String concat
    RUN_TEST(it_should_concat_string_iterative);
    RUN_TEST(it_should_concat_string_recursive);

    // String Permutation
    RUN_TEST(it_should_test_string_permutations);
    RUN_TEST(it_should_test_string_combinations_k);

    // Factorial
    RUN_TEST(it_should_calculate_factorial_iterative);
    RUN_TEST(it_should_calculate_factorial_recursive);

    // Fibonacci
    RUN_TEST(it_should_calculate_fibonacci_iterative);
    RUN_TEST(it_should_calculate_fibonacci_recursive);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}