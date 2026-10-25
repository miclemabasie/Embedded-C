/*
 * Ask the user to enter a five-digit password one digit at a time.
 * The valid passwords are 36579 (opens door 1) and 36581 (opens door 2).
 * Check each digit as it is entered. If a digit is incorrect, show an
 * error message and restart. If all five digits match a valid password,
 * display which door opened and end the program.
 */

#include <stdio.h>

enum
{
    ON,
    OFF,
    IDLE,
    FIRST_DIGIT,
    SECOND_DIGIT,
    THIRD_DIGIT,
    FOURTH_DIGIT,
    FIFTH_DIGIT,
    OPEN_DOOR1,
    OPEN_DOOR2,
    ERROR
};

int main(void)
{

    int state = IDLE;
    int run = ON;
    int d1, d2, d3, d4, d5;

    while (run == ON)
    {
        switch (state)
        {
        case IDLE:
            printf("This is a passowrd state machine.\n Please enter digit per digit to open door 1 or door 2.\n Enter first digit: ");
            scanf("%d", &d1);
            // update the state if number is correct
            if (d1 == 3)
                state = FIRST_DIGIT; // update the state
            else
                state = ERROR;
            break;

        case FIRST_DIGIT:
            printf("Enter second digit: ");
            scanf("%d", &d2);
            if (d2 == 6)
                state = SECOND_DIGIT;
            else
                state = ERROR;

            break;

        case SECOND_DIGIT:
            printf("Enter the third digit: ");
            scanf("%d", &d3);
            if (d3 == 5)
                state = THIRD_DIGIT;
            else
                state = ERROR;
            break;
            // 36579 (opens door 1) and 36581 (opens door 2).

        case THIRD_DIGIT:
            printf("Enter the fourth digit: ");
            scanf("%d", &d4);
            if (d4 == 7 || d4 == 8)
                state = FOURTH_DIGIT;
            else
                state = ERROR;
            break;

        case FOURTH_DIGIT:
            printf("Enter the fifth digit: ");
            scanf("%d", &d5);
            if (d5 == 9 || d5 == 1)
                state = FIFTH_DIGIT;
            else
                state = ERROR;
            break;

        case FIFTH_DIGIT:
            printf("End of password entry.\n");
            if (d4 == 7 && d5 == 9)
                state = OPEN_DOOR1;
            else if (d4 == 8 && d5 == 1)
                state = OPEN_DOOR2;
            break;

        case OPEN_DOOR1:
            printf("Congratulations, you opened door 1\n");
            run = OFF;
            break;
        case OPEN_DOOR2:
            printf("Congratulations, you opened door 2\n");
            run = OFF;
            break;

        case ERROR:
            printf("Incorrect passowrd. Try again.\n");
            state = IDLE;
            break;

        default:
            break;
        }
    }

    return 0;
}