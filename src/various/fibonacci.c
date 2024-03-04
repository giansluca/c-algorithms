#include <stdio.h>

int fibonacci_rec(int number);
int fibonacci_ite(int number);

/**
 * Fibonacci number is the sum of two previous fibonacci numbers
 */

void fibonacci_recursion() {
    int number = 9;
    int fib = fibonacci_rec(number);

    printf("The %dth fibonacci number is: %d\n", number, fib);
}

void fibonacci_iteration() {
    int number = 8;
    int fib = fibonacci_ite(number);

    printf("The %dth fibonacci number is: %d\n", number, fib);
}

int fibonacci_rec(int number) {
    if (number <= 1)
        return number;

    return fibonacci_rec(number - 1) + fibonacci_rec(number - 2);
}

int fibonacci_ite(int number) {
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
