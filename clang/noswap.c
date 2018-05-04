#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
  int x, y;
  // Getting input from user, use scan[formatted];
  // &x is to get the memory address.
  printf("x: ");
  scanf("%i", &x);
  printf("y: ");
  scanf("%i", &y);

  printf("%i, &i\n", x, y);
  swap(&x, &y);
  printf("%i, %i\n", x, y);
  return 0;
}

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
