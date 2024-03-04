#include "../../src/sorting/bubble_sort.h"
#include "../../src/sorting/insertion_sort.h"
#include "../../src/sorting/merge_sort.h"
#include "../../src/sorting/quick_sort.h"
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

    // when
    selection_sort_string_array(array, size);

    // then
    char *expected[] = {"22", "aa", "aaa", "flower", "gigi", "paper", "soap", "true", "xx", "zzz"};
    TEST_ASSERT_EQUAL_STRING_ARRAY(expected, array, size);
}

// Insertion sort
void it_should_sort_with_insertion_sort_iterative() {
    // given
    int array[] = {4, 2, 1, 6, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    insertion_sort_iterative(array, size);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_insertion_sort_recursive() {
    // given
    int array[] = {5630, 4, 2, 1, 6, 3500, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    insertion_sort_recursive(array, size);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3500, 5630};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_insertion_sort_nearest_to_given_number() {
    // given
    int array[] = {4, -1, 13, 26, 8, 35, 3, 7, -4, 756, -99, 11};
    int number = 10;
    int size = sizeof(array) / sizeof(array[0]);

    insertion_sort_nearest_to_given_number(array, size, number);

    // then
    int expected[] = {11, 8, 13, 7, 4, 3, -1, -4, 26, 35, -99, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

// Merge sort
void it_should_sort_with_merge_sort_recursive() {
    // given
    int array[] = {5630, 4, 2, 1, 6, 3500, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    merge_sort_recursive(array, 0, size - 1);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3500, 5630};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_merge_sort_iterative() {
    // given
    int array[] = {5630, 4, 2, 1, 6, 3501, 8, 5, 3, 7, -4, 756, -9, -89};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    merge_sort_iterative(array, size);

    // then
    int expected[] = {-89, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3501, 5630};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

// Quick sort
void it_should_sort_with_quick_sort_recursive() {
    // given
    int array[] = {5630, 4, 2, 1, 6, 3500, 8, 5, 3, 7, -4, 756, -9, -88};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    quick_sort_recursive(array, 0, size - 1);

    // then
    int expected[] = {-88, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3500, 5630};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

void it_should_sort_with_quick_sort_iterative() {
    // given
    int array[] = {5630, 4, 2, 1, 6, 3501, 8, 5, 3, 7, -4, 756, -9, -88};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    quick_sort_iterative(array, 0, size - 1);

    // then
    int expected[] = {-88, -9, -4, 1, 2, 3, 4, 5, 6, 7, 8, 756, 3501, 5630};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
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

    // Insertion sort
    RUN_TEST(it_should_sort_with_insertion_sort_iterative);
    RUN_TEST(it_should_sort_with_insertion_sort_recursive);
    RUN_TEST(it_should_sort_with_insertion_sort_nearest_to_given_number);

    // Merge sort
    RUN_TEST(it_should_sort_with_merge_sort_recursive);
    RUN_TEST(it_should_sort_with_merge_sort_iterative);

    // Quick sort
    RUN_TEST(it_should_sort_with_quick_sort_recursive);
    RUN_TEST(it_should_sort_with_quick_sort_iterative);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}