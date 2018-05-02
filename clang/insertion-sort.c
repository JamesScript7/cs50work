#include <stdio.h>

int main(void)
{
	int i, j;
	int arr[6] = {5,2,1,3,6,4};
	int len = sizeof(arr) / sizeof(arr[0]);
	int swappable;

	for (i = 1; i < len; i++)
	{
		while (arr[i] < arr[i - 1])
		{
			swappable = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = swappable;

			if (i > 1)
				i--;
		}
	}

	printf("Array has been insertion sorted!\n");
	printf("{");

	for (j = 0; j < len; j++)
	{
		if (j < len - 1)
			printf("%i, ", arr[j]);
		else
			printf("%i}\n", arr[j]);
	}

	return 0;
}

// Worst case senario (Big O): Array is in reverse order so
// it shifts each element "n" positions for the insertion.
// O(n**2)

// Best case senario (Big Omega): Array is sorted but needs
// to iterate over each of the element at least once.
// Omega(n)
