#include <stdio.h>

int factorial_rec(int number);
int factorial_ite(int number);

/**
 * Factorial of a number is multiplication of all integers smaller than or equal
 * to number
 */

void factorial_recursion() {
    int number = 5;
    int factorial = factorial_rec(number);

    printf("Factorial of %d is: %d\n", number, factorial);
}

void factorial_iteration() {
    int number = 6;
    int factorial = factorial_ite(number);

    printf("Factorial of %d is: %d\n", number, factorial);
}

int factorial_rec(int number) {
    // base case - return if number is equal to 1
    if (number == 1)
        return 1;

    // recursive call
    return number * factorial_rec(number - 1);
}

int factorial_ite(int number) {
    int factorial = 1;

    for (int i = 1; i <= number; i++) {
        factorial = factorial * i;
    }

    return factorial;
}
