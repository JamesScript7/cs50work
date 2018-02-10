#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for height until valid input:
	int num;
	do
	{
		num = get_int("Enter height(number between 1-23): ");
	}
	while (num < 1 || num > 23);

	// Height Iterator:
	for (int i = 0; i < num; i++)
	{
		// Print spaces:
		for (int j = num; j > (i + 1); j--)
		{
			printf("%c", ' ');
		}

		// Pyramid Iterator:
		for (int k = 0; k < 2; k++)
		{
			//Print a pyramid:
			for (int l = 0; l < (i + 1); l++)
			{
				printf("#");
			}

			// Print 2 spaces to separate pyramids:
			printf("%s", "  ");
		}

		// New line at the end of loop:
		printf("\n");
	}

	return 0;
}
