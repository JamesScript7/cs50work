#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>

//isalpha(x), isupper(x), islower(x) returns a boolean.
// [A = 65, Z = 90], [a = 97, z = 122]

// argc = number of arguments passed.
// argv = list of arguments passed.
int main(int argc, string argv[])
{
	// if arguments are not supplied or is a number:
	if (argc < 2 || atoi(argv[1]))
	{
		return 1;
	}
	else if (argc > 2)
	{
		return 1;
	}

	// Key is stored here:
	string keyText = argv[1];

	// Checks key for any non alpha characters:
	for (int l = 0; l < strlen(keyText); l++)
	{
		if (!isalpha(keyText[l]))
		{
			return 1;
		}
	}

	// Prompt user for plaintext:
	string plainText = get_string("plaintext: ");

	//Print enciphered text:
	printf("ciphertext: ");

	// Takes user input and converts each char to int:
	for (int i = 0, n = strlen(plainText), j = 0; i < n; i++)
	{
		// Converting string to ASCII value:
		int ptASCII = plainText[i];
		int keyASCII = keyText[(i - j) % strlen(ketText)];

		// ASCII positions:
		int asciiPositionUpper = 65;
		int asciiPositionLower = 97;

		char cipherText;

		// Normalizes the keyASCII:
		if (isupper(keyText[i % strlen(keyText)]))
		{
			keyASCII -= asciiPositionUpper;
		}
		else if (islower(keyText[i % strlen(keyText)]))
		{
			keyASCII -= asciiPositionLower;
		}

		// Loops through plainText and returns modified character:
		if (plainText[i] == ' ')
		{
			j++;
			printf(" ");
		}
		else if (!isalpha(plainText[i]))
		{
			j++;
			printf("%c", plainText[i]);
		}
		else if (isupper(plainText[i]))
		{
			ptASCII -= asciiPositionUpper;
			cipherText = ((ptASCII + keyASCII) % 26) + asciiPositionUpper;
			printf("%c", cipherText);
		}
		else if (islower(plainText[i]))
		{
			ptASCII -= asciiPositionLower;
			cipherText = ((ptASCII + keyASCII) % 26) + asciiPositionLower;
			printf("%c", cipherText);
		}
	}

	printf("\n");
	return 0;
}
