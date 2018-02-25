#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for pyramid height that is between [0,23]
	int x;
	do
	{
		x = get_int("Enter height of the pyramid between 1 and 23: ");
	}
	while (x > 23 || x < 0);

	// Print number that is stored in x:
	// printf("x is: %i\n", x);

	// Iterate to build the half pyramid
	for (int i = 0; i < x; i++)
	{
		// Draw spaces
		for (int j = x; j > i + 1; j--)
		{
			printf("%c", ' ');
		}

		// Draw hashes
		for (int k = 0; k < i + 2; k++)
		{
			printf("#");
		}

		// New line
		printf("\n");
	}

	return 0;
}
