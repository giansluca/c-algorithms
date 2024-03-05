#include "../../src/searching/binary_search.h"
#include "../unity/unity.h"
#include <stdio.h>

// Binary search
void it_should_find_a_number_index_using_binary_search_iterative() {
    // given
    int array[] = {-30, -9, 1, 4, 6, 8, 30, 72, 453, 756};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    int index_found = binary_search_iterative(array, size, 30);
    int index_not_found = binary_search_iterative(array, size, 31);

    // then
    TEST_ASSERT_EQUAL_INT(6, index_found);
    TEST_ASSERT_EQUAL_INT(-1, index_not_found);
}

void it_should_find_a_number_index_using_binary_search_recursive() {
    // given
    int array[] = {-30, -9, 1, 4, 6, 8, 30, 72, 453, 756};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    int index_found = binary_search_recursive(array, 0, size - 1, 30);
    int index_not_found = binary_search_recursive(array, 0, size - 1, 31);

    // then
    TEST_ASSERT_EQUAL_INT(6, index_found);
    TEST_ASSERT_EQUAL_INT(-1, index_not_found);
}

void it_should_find_first_and_last_number_index_occurrence() {
    // given
    int number_present = 8;
    int number_not_present = 7;
    int array[] = {-9, -3, 8, 8, 8, 8, 8, 72, 108, 830, 756};
    int size = sizeof(array) / sizeof(array[0]);
    bool search_first = false;

    // when
    int first_index_found = binary_search_first_or_last_occurrence(array, size - 1, number_present, true);
    int last_index_found = binary_search_first_or_last_occurrence(array, size - 1, number_present, false);
    int index_not_found = binary_search_first_or_last_occurrence(array, size - 1, number_not_present, search_first);

    // then
    TEST_ASSERT_EQUAL_INT(2, first_index_found);
    TEST_ASSERT_EQUAL_INT(6, last_index_found);
    TEST_ASSERT_EQUAL_INT(-1, index_not_found);
}

void it_should_find_numer_of_number_occurrences() {
    // given
    int number_present = 8;
    int number_not_present = 7;
    int array[] = {-9, 8, 8, 8, 8, 8, 8, 8, 108, 830, 756};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    int occurrences_yes = binary_search_count_occurrences(array, size, number_present);
    int occurrences_no = binary_search_count_occurrences(array, size, number_not_present);

    // then
    TEST_ASSERT_EQUAL_INT(7, occurrences_yes);
    TEST_ASSERT_EQUAL_INT(0, occurrences_no);
}

int main() {
    UNITY_BEGIN();

    // Binary search
    RUN_TEST(it_should_find_a_number_index_using_binary_search_iterative);
    RUN_TEST(it_should_find_a_number_index_using_binary_search_recursive);
    RUN_TEST(it_should_find_first_and_last_number_index_occurrence);
    RUN_TEST(it_should_find_numer_of_number_occurrences);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}