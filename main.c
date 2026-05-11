#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(void)
{
    struct Person
    {
        int age : 10;
        int ismarried : 1;
    } typedef Person;

    Person person1 = {23, 0};
    printf("The program is working %d, %d", person1.age, person1.ismarried);
    return 0;
}