// DES-based crypt function:
#define _XOPEN_SOURCE
#include <unistd.h>

#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
	if (argc < 2 || argc > 2)
	{
		return 1;
	}

	// The hashed Password:
	string hashedPassword = argv[1];
	printf("hashedPassword: %s\n", hashedPassword);

	// Salt is a 2 character string [a-zA-Z0-9] used to
	// perturb the algorithm in 4096 different ways.

	// theSalt: is the first 2 characters of a hashed password:
	char theSalt[3];
	sprintf(theSalt, "%c%c", argv[1][0], argv[1][1]);

	// Key is a user's typed password. We need to find the key.
	// char theKey[6];
	// printf("%d\n", theKey);

	// LOOP
	for (int i = 'A', j = 'a'; i <= 'Z'; i++, j++)
	{
		// Convert i to char:
		char attempt[2];
		sprintf(attempt, "%c", i);

		// printf("string: %s\n", crypt("A", theSalt));
		printf("check: %s\n", crypt(attempt, theSalt));

		// char *crypt(const char *key, const char *salt);
		// printf("%s\n", crypt(theKey, theSalt));

	}

	return 0;
}
