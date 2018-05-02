#include <stdio.h>

int main(void)
{
	int i, j, k;
	// The unsorted array
	int arr[7] = {3,1,6,4,2,5,7};
	int len = sizeof(arr) / sizeof(arr[0]);
	int smallest;
	int swapped;

	for (i = 0; i < len; i++)
	{
		smallest = len + 1;

		for (j = i; j < len; j++)
		{
			if (arr[j] < smallest)
			{
				smallest = arr[j];
				swapped = j;
			}
			if (j == len - 1)
			{
				arr[swapped] = arr[i];
				arr[i] = smallest;
			}
		}
	}

	printf("Array has been selection sorted!\n");
	printf("{");

	for (k = 0; k < len; k++)
	{
		if (k < len - 1)
			printf("%i, ", arr[k]);
		else
			printf("%i}\n", arr[k]);
	}

	return 0;
}

// Worst case senario (Big O): Iterating over each of the
// elements of the array.
// O(n**2)

// Best case senario (Big Omega): Exactly the same because
// it has to iterate over all the elements to know that
// it has been sorted.
// Omega(n**2)
