#include <stdio.h>

int main(void)
{

    int x = 0b0001001010000100;

    printf("Binary of X = %b\n", x);
    // printf("Decimal of X = %d\n", x);

    printf("inverse by y: %b\n", x & ~(0x01 << 7));
    return 0;
}