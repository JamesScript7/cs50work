#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
	// argc: the number of arguments passed.
	// argv: the list of arguments passed.
	// Both include ./<program> as the first argument.

	// Argument checker:
	if (argc < 2 || argc > 2)
	{
		printf("Usage: ./caesar k\n");
		return 1;
	}

	// Converts the command-line input "string" to "integer":
	// Note: If argv[1] is not an integer it returns 0;
	int k = atoi(argv[1]);
	// printf("%i\n", k);

	// Prompt user for plaintext:
	string ptext = get_string("plaintext: ");

	// isalpha(x), isupper(x), islower(x) returns a boolean.
	// [A = 65, Z = 90], [a = 97, z = 122]

	// Print enciphered text:
	printf("ciphertext: ");

	for (int i = 0, n = strlen(ptext); i < n; i++)
	{
		// Convert string to ASCII integer:
		int c = ptext[i];
		char ctext;
		int x;
		// printf("i%\n", c);
		
		if ( !isalpha(ptext[i]) )
		{
			printf("%c", ptext[i]);
		} else if ( isupper(ptext[i]) )
		{
			x = 65;
			ctext = (((c-x) + k) % 26) + x;
			printf("%c", ctext);
		} else if ( islower(ptext[i]) )
		{
			x = 97;
			ctext = (((c-x) + k) % 26) + x;
			printf("%c", ctext);
		}
	}

	printf("\n");
	return 0;
}
