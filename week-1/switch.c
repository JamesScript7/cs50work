#include <cs50.h>
#include <stdio.h>

int main(void)
{
	// Prompt user for charater
	char c = get_char("Answer: ");

	// Switch statement
	switch (c)
	{
		case 'Y':
		case 'y':
			printf("yes\n");
			break;
		case 'N':
		case 'n':
			printf("no\n");
			break;
	}
}
