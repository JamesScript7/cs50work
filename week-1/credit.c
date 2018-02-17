#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for cc number:
	long long cardnum = get_long_long("Number: ");
	string cardtype;

	int x = 51;
	
	// AMEX: 15-digit && start == 34 || start == 37
	// MASTERCARD: 16-digit && start >= 51 && start <= 55
	// VISA: 13-digit || 16-digit && start == 4

	if (x == 4)
	{
		cardtype = "VISA";
	}
	else if (x >= 51 && x <= 55)
	{
		cardtype = "MASTERCARD";
	}
	else if (x == 34 || x == 37)
	{
		cardtype = "AMEX";
	}
	else
	{
		cardtype = "INVALID";
		printf("%s\n", cardtype);
		return 0;
	}

	printf("%lli\n", cardnum);
	printf("%s\n", cardtype);
	return 0;
}
