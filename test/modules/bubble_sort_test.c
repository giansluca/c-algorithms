#include "../../src/sorting/bubble_sort.h"
#include "../unity/unity.h"
#include <stdio.h>

void it_should_sort_with_iterative_bubble_sort() {
    // given
    int array[] = {4, 2, 1, 6, 8, 5, 3, 7, -4, 756};
    int size = sizeof(array) / sizeof(array[0]);

    // when
    bubble_sort_ite(array, size);

    // then
    int expected[] = {-4, 1, 2, 3, 4, 5, 6, 7, 8, 756};
    TEST_ASSERT_EQUAL_INT_ARRAY(expected, array, size);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(it_should_sort_with_iterative_bubble_sort);

    return UNITY_END();
}

void setUp(void) {
    //
}

void tearDown(void) {
    //
}