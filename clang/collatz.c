#include <stdio.h>

int collatz(int n)
{
  if (n == 1)
  {
		return 0;
  }
  else if (n % 2 == 0)
  {
    printf("Even => %i\n", n);
    return 1 + collatz(n / 2);
  }
  else if (n % 2 == 1)
  {
    printf("Odd => %i\n", n);
    return 1 + collatz((3 * n) + 1);
  }
	else
	{
		return 0;
	}
}

int main(void)
{
  printf("%i\n", collatz(3));
  return 0;
}
