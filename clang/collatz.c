#include <stdio.h>

int collatz(int n, int c)
{
  if (n == 1)
  {
    printf("\nTotal Steps: %i\n", c);
  }
  else if (n % 2 == 0)
  {
    printf("Even => %i\n", n);
    return collatz(n / 2, c + 1);
  }
  else if (n % 2 == 1)
  {
    printf("Odd => %i\n", n);
    return collatz((3 * n) + 1, c + 1);
  }
}

int main(void)
{
  collatz(3, 0);
  return 0;
}
