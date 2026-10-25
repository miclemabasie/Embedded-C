/*
Write a program that asks the user to enter two integers, obtains the numbers from the user,
 then prints the larger number followed by the words “is larger.”
  If the numbers are equal, print the message “These numbers are equal.” 
  Use only the single-selection form of the if statement you learned in this chapter.
*/
#include <stdio.h>

int main(void) {

    int x, y;
    printf("Enter 2 numbers: ");
    scanf("%d %d", &x, &y);

    if(x > y){
        printf("%d is larger.\n", x);
    }else if(x < y) {
        printf("%d is larger.\n", y);

    }else {
        printf("These numbers are equal.\n");
    }
    return 0;
}