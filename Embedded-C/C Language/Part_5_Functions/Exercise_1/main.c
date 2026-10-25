/*
Write a function integerPower(base, exponent) that returns the value of base exponent For example, integerPower( 3, 4 ) = 3 * 3 * 3 * 3.
 Assume that exponent is a positive, nonzerointeger, and base is an integer.
  Function integerPower should use for to control the calculation. Do not use any math library functions.
*/

#include <stdio.h>
#include <stdint.h>

int integerPower(int base, int exponent);

int main(void)
{

    uint32_t base, exponent;
    printf("Welcome to the Base to Power program.\n");
    printf("Enter Base: ");
    scanf("%d", &base);

    printf("Enter Exponent: ");
    scanf("%d", &exponent);

    printf("%d raised to %d is: %d\n", base, exponent, integerPower(base, exponent));

    return 0;
}

int integerPower(int base, int exponent)
{
    int res = 1;
    for (int i = 0; i < exponent; i++)
    {
        res *= base;
    }

    return res;
}