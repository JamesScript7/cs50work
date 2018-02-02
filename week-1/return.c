#include <cs50.h>
#include <stdio.h>

int square(int n);

int main(void)
{
	// Prompt user for x
	int x = get_int("x: ");
	printf("%i\n", square(x));
}

int square(int n)
{
	return n * n;
}
