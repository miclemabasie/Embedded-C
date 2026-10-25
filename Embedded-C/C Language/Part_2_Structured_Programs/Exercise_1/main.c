/*
Write a C program that tracks fuel efficiency across multiple tankfuls of gasoline.

For each tankful, ask the user to enter the gallons used and the miles driven. Calculate that tank’s fuel efficiency by dividing miles driven by gallons used, then display the result in miles per gallon.

Keep a running total of the miles-per-gallon results and count how many tankfuls have been entered. Continue asking for input until the user enters -1 for gallons. Treat -1 as a sentinel value: it signals the end of input and is not a tankful, so do not ask for miles or include it in any calculation.

When input ends, calculate the overall average by dividing the sum of the tank-by-tank miles-per-gallon results by the number of tankfuls entered. Display that average and end the program.

Important: The overall average requested here is the arithmetic mean of the individual tankful MPG values. It is different from combined fuel efficiency, which would divide the total miles by the total gallons.
*/
#include <stdio.h>
#include <stdint.h>


int main(void) {
    float miles = 0;
    float gallons = 0;  
    uint8_t count = 0;
    float miles_per_gallon = 0;
    float total_miles_per_gallon = 0;
    while(miles != -1){

        printf("Enter Miles (-1 to stop): ");
        scanf("%f", &miles);
        if(miles == -1) {
            miles_per_gallon ? printf("The total average usage = %.2lfMPG\n", total_miles_per_gallon / count) : printf("No input!\n");
            break;
        }
        printf("Enter gallons: ");
        scanf("%f", &gallons);

        miles_per_gallon = miles / gallons;
        total_miles_per_gallon += miles_per_gallon;
        printf("This trip used: %.2lfMPG\n", miles_per_gallon);
        count++;
    }

return 0;
}