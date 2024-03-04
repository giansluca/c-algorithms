#include <stdio.h>

/**
 * Factorial of a number is multiplication of all integers smaller than or equal
 * to number
 */

int factorial_recursive(int number) {
    // base case - return if number is equal to 1
    if (number == 1)
        return 1;

    return number * factorial_recursive(number - 1);
}

int factorial_iterative(int number) {
    int factorial = 1;

    for (int i = 1; i <= number; i++) {
        factorial = factorial * i;
    }

    return factorial;
}
