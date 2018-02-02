#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for x and y
	int x = get_int("x: ");
	int y = get_int("y: ");

	// Check x and y
	if (x > y)
	{
		printf("%i is greater than %i\n", x, y);
	}
	else if (x < y)
	{
		printf("%i is less than %i\n", x, y);
	}
	else
	{
		printf("%i is equal to %i\n", x ,y);
	}
}
