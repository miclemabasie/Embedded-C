/*  Write a program that sums a sequence of integers. Assume that the first integer read with scanf specifies the number of values remaining to be entered.
    Your program should read only one value each time scanf is executed. A typical input sequence might be 5 100 200 300 400 500
    where the 5 indicates that the subsequent five values are to be summed */

#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint8_t count = 0;
    int result = 0, n = 0;
    printf("Enter number of values to sum: ");
    scanf("%hhd", &count);

    for(uint8_t i = 0; i < count; i++){
        printf("Enter Value No: %d: ", i+1);
        scanf("%d", &n);
        result += n;
    }

    printf("The sum of all numbers are: %d\n", result);

    return 0;
}