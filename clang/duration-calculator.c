#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
// Note: type string is only available through <cs50.h>
int duration(string fraction);

int main(void)
{
  duration("1/2");
  return 0;
}

int duration(string fraction)
{
  // 2nd slot for the closing char '\0'
  char fraction0[2];
  char fraction2[2];
  int numerator;
  int denominator;
  int totalEigths;

  // Isolates the numerator and denominator
  sprintf(fraction0, "%c", fraction[0]);
  sprintf(fraction2, "%c", fraction[2]);

  // Checks if the character input is an alphabet
  if (isalpha(fraction0[0]) || isalpha(fraction2[0]))
  {
    printf("%s\n", "Check that your fraction doesn't contain a letter.");
    return 1;
  }

  // atoi() converts ASCII to int
  numerator = atoi(fraction0);
  denominator = atoi(fraction2);

  // Checks if the denominator is a multiple of 2
  if (denominator % 2 != 0)
  {
    printf("%s\n", "Denominator is not a multiple of 2.");
    return 1;
  }

  totalEigths = numerator * (8 / denominator);

  printf("%i\n", totalEigths);
  return totalEigths;
}
