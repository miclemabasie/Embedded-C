/*
Write a function that takes the time as three integer arguments (for hours, minutes, and seconds)
 and returns the number of seconds since the last time the clock “struck 12.”
  Use this function to calculate the amount of time in seconds between two times, both of which are within one 12-hour cycle of the clock.
*/

#include <stdio.h>
#include <stdint.h>

unsigned int TimeSince12H(uint32_t hour, uint32_t minutes, uint32_t seconds);

int main(void)
{
  uint32_t hours, minutes, seconds;
  printf("Enter Hour: ");
  scanf("%d", &hours);
  printf("Enter Minutes: ");
  scanf("%d", &minutes);
  printf("Enter Seconds: ");
  scanf("%d", &seconds);

  printf("Total seconds passed since the clock struck 12, at %d:%d:%d: = %d Seconds\n", hours, minutes, seconds, TimeSince12H(hours, minutes, seconds));

  return 0;
}

uint32_t TimeSince12H(uint32_t hour, uint32_t minutes, uint32_t seconds)
{
  uint32_t hours_to_seconds = (hour % 12) * 60 * 60;
  uint32_t minutes_to_seconds = (minutes) * 60;
  uint32_t total_seconds = hours_to_seconds + minutes_to_seconds + seconds;
  return total_seconds;
}