#include <stdio.h>

int factorial(int n)
{
  // If there's only one line then
  // you can get rid of the curly braces.
  if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}

int main(void)
{
  printf("%i", factorial(5));
  return 0;
}
