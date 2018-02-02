#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for x
	float x = get_float("x: ");

	// Prompt user for y
	float y = get_float("y: ");

	// Perform division on the floating point integers
	printf("%f divided by %f is %.2f\n", x, y, x / y);
}
