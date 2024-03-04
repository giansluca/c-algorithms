#include <stdio.h>

/**
 * Fibonacci number is the sum of two previous fibonacci numbers
 */

int fibonacci_recursive(int number) {
    if (number <= 1)
        return number;

    return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

int fibonacci_iterative(int number) {
    int a = 0;
    int b = 1;
    int c;

    if (number == 0) {
        return a;
    }

    for (int i = 2; i <= number; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}
