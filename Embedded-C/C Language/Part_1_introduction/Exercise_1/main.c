/* Write a program that asks the user to enter two numbers, obtains them from the user, and prints their sum, product, difference, quotient, and remainder. */

#include <stdio.h>

int main(void) {
    double x, y;
    printf("Enter num1: ");
    scanf("%lf", &x);
    printf("Enter num2: ");
    scanf("%lf", &y);

    // print out Sum
    printf("Sum: %.2lf\n", x + y);
    printf("Product: %.2lf\n", x * y);
    printf("Difference: %.2lf\n", x - y);
    printf("Quotient: %.2lf\n", x/y);
    printf("Remainder: %d \n", (int)x % (int)y);
    return 0;
}