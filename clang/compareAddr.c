#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compare(void);
int copy(void);

int main(void)
{
	// compare();
	copy();
	return 0;
}

int compare(void)
{
	// string is just a placeholder for char *
	// string x = get_string("x: ");
	// string y = get_string("y: ");

	char *x = get_string("x: ");
	char *y = get_string("y: ");

	// Issue: Input is the same string but "Different" is printed.
	// Solution: Replace (x == y) to (strcmp(x, y) == 0)
	if (strcmp(x, y) == 0)
		printf("Same.\n");
	else
		printf("Different.\n");

	return 0;
}

int copy(void)
{
	// string s = get_string("s: ");
	// string t = s;
	
	int i;
	char *s = get_string("s: ");
	// it can return NULL (not to be confused with NUL \0)
	// (!s) means 'if not 0' can be written (s == NULL)
	if (!s) return 1;

	// char *t = s;
	// allocate memory for another string with malloc!
	// fyi: + 1 to strlen to accomodate \0 (NUL)
	// fyi: sizeof(char) == 1
	char *t = malloc((strlen(s) + 1) * sizeof(char));
	if (!t) return 1;

	// You have the manually iterate the string into 't'
	for (i = 0; i <= strlen(s); i++)
	{
		t[i] = s[i];
		// Since 't' is the memory address, you can
		// access the next block sequentially.
		printf("%c\n", *(s + i));
	}

	if (strlen(t) > 0)
	{
		t[0] = toupper(t[0]);
	}

	// Issue: int 't' is getting capitalized as well.
	// Solution: 't' accesses from a differnt block of memory
	// that had a different memory address from 's'
	printf("s: %s\n", s);
	printf("t: %s\n", t);
	
	return 0;
}
