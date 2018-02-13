#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for change:
	float num = get_float("Enter your change: ");

	// Initialize change counter:
	int change = num * 100;
	int quarter = 0.25 * 100;
	int dime = 0.10 * 100;
	int nickel = 0.05 * 100;
	int penny = 0.01 * 100;
	int total = 0;

	while (change > 0)
	{
		if (change - quarter >= 0)
		{
			change -= quarter;
			total++;
			// printf("%i\n", change);
		} else if (change - dime >= 0)
		{
			change -= dime;
			total++;
			// printf("%i\n", change);
		} else if (change - nickel >= 0)
		{
			change -= nickel;
			total++;
			// printf("%i\n", change);
		} else if (change - penny >= 0)
		{
			change -= penny;
			total++;
			// printf("%i\n", change);
		} else {
			change = 0;
		}
	}

	printf("%i\n", total);
	return total;
}
