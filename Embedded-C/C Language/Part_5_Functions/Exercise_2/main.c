/*
Write a function multiple that determines for a pair of integers whether the second integer is a multiple of the first.
The function should take two integer arguments and return 1 (true)
if the second is a multiple of the first, and 0 (false) otherwise.
Use this function in a program that inputs a series of pairs of integers.
*/
#include <stdio.h>

int isMultiple(int n1, int n2);

int main(void)
{
    int n1, n2;
    printf("Enter n1 and n2: ");
    scanf("%d %d", &n1, &n2);
    isMultiple(n1, n2) ? printf("Yes: %d is a multiple of %d\n", n2, n1) : printf("No: %d is not a multiple of %d\n", n2, n1);
    return 0;
}

int isMultiple(int n1, int n2)
{
    if (n1 % n2 == 0)
        return 1;
    else
        return 0;
}