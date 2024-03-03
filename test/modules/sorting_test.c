#include "../../src/sorting/bubble_sort.h"
#include "../../src/sorting/selection_sort.h"
#include "../unity/unity.h"
#include <stdio.h>

// Bubble sort
void it_should_sort_with_bubble_sort_iterative() {
    // given
    int array[] = {4, 2, 1, 6, 8, 5, 3, 7, -4, 756};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    bubble_sort_iterative(array, size);

    // then
    int expected[] = {-4, 1, 2, 3, 4, 5, 6, 7, 8, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_bubble_sort_recursive() {
    // given
    int array[] = {4, 2, 1, 6, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    bubble_sort_recursive(array, size);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_bubble_sort_a_string_array() {
    // given
    char *array[] = {"aa", "xx", "paper", "true", "soap", "22", "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);

    bubble_sort_string_array(array, size);

    // then
    char *expected[] = {"22", "aa", "aaa", "flower", "gigi", "paper", "soap", "true", "xx", "zzz"};
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, size);
}

// Selection sort
void it_should_sort_with_selection_sort_iterative() {
    // given
    int array[] = {4, 2, 1, 6, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    selection_sort_iterative(array, size);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_selection_sort_recursive() {
    // given
    int array[] = {4, 2, 1, 6, 3500, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    selection_sort_recursive(array, size, 0);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3500};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_selection_sort_a_string_array() {
    // given
    char *array[] = {"aa", "xx", "paper", "true", "soap", "22", "flower", "gigi", "zzz", "aaa"};
    int size = sizeof(array) / sizeof(array[0]);

    selection_sort_string_array(array, size);

    // then
    char *expected[] = {"22", "aa", "aaa", "flower", "gigi", "paper", "soap", "true", "xx", "zzz"};
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, size);
}

int main() {
    UNITY_BEGIN();

    // Bubble sort
    RUN_TEST(it_should_sort_with_bubble_sort_iterative);
    RUN_TEST(it_should_sort_with_bubble_sort_recursive);
    RUN_TEST(it_should_sort_with_bubble_sort_a_string_array);

    // Selection sort
    RUN_TEST(it_should_sort_with_selection_sort_iterative);
    RUN_TEST(it_should_sort_with_selection_sort_recursive);
    RUN_TEST(it_should_sort_with_selection_sort_a_string_array);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}