#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
	int x, y;
	// Getting input from user use scanf[ormatted];
	// &x
	printf("x: ");
	scanf("%i", &x);
	printf("y: ");
	scanf("%i", &y);

	printf("%i, %i\n", x, y);
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
