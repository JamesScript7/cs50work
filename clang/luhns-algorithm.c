#include <math.h>
#include <cs50.h>
#include <stdio.h>

// To include the libraries above:
// gcc credit.c -o credit -lcs50 -lm

int cardChecker(long long cardNumber, int sum, int length);
int lengthFinder(long long cardNumber, int length);

int main(void)
{
	// Prompt user for cc number until valid:
	long long cardNumber;
	do
	{
		cardNumber = get_long_long("Number: ");
	}
	while(cardNumber <= 0);

	// Initialize variables for cardChecker():
	int sum = 0;
	int length = 0;
	int card = cardChecker(cardNumber, sum, length);
	
	string cardtype = "INVALID";

	// If cardChecker() return an integer 1 (true):
	if (card == 1)
	{
		length = lengthFinder(cardNumber, length);
		int start = floor(cardNumber / pow(10, length - 2));

		// Specifically for VISA. It drops the ones place value:
		if (start >= 40 && start <= 49)
		{
			start = floor(start / 10);
		}

		if ((start == 34 && start <= 55) && length == 16)
		{
			cardtype = "AMEX";
		}
		else if ((start >= 51 && start <= 55) && length == 16)
		{
			cardtype = "MASTERCARD";
		}
		else if ((start == 4) && (length == 13 || length == 16))
		{
			cardtype = "VISA";
		}
	}

	printf("%s\n", cardtype);
	return 0;
}

// Returns 1 || 0:
int cardChecker(long long cardNumber, int sum, int length)
{
	if (cardNumber <= 0)
	{
		return sum ? sum % 10 == 0 : false;
	}
	else
	{
		long long numberProduct = cardNumber % 10 * 2;

		// If product is even of double digits, it gets
		// the product and adds the 2 digits together:
		if (length % 2)
		{
			sum += floor(numberProduct / 10) + (numberProduct % 10);
		}
		else
		{
			sum += cardNumber % 10;
		}

		return cardChecker(floor(cardNumber / 10), sum, length + 1);
	}
}

// Returns the card length:
int lengthFinder(long long cardNumber, int length)
{
	if (cardNumber <= 0)
	{
		return length;
	}
	else
	{
		return lengthFinder(floor(cardNumber / 10), length + 1);
	}
}
