#include <stdio.h>

int main(void)
{
	int i, j, k;
	// The unsorted array
	int arr[7] = {3,1,6,4,2,5,7};
	int len = 7;

	for (i = 0; i < len; i++)
	{
		int smallest = 8;

		for (j = i; j < len; j++)
		{
			int swapped;
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
