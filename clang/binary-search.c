#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int arr[14] = {2,5,7,9,14,26,45,78,98,103,234,365,657};
	int len = sizeof(arr) / sizeof(arr[0]);
	int target = 14;
	bool found = false;
	int iterations = 0;
	int start = 0;
	int end = len;
	int middle = len / 2;

	while ((end - start) >= 0)
	{
		iterations++;
		if (target == arr[middle])
		{
			found = true;
			break;
		}
		else if (target > arr[middle])
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
		middle = (end + start) / 2;
	}

	if (found)
		printf("Found target: %i, in arr[%i], after %i iterations.\n", target, middle, iterations);
	else
		printf("Target not found after %i iterations.\n", iterations);
		
		return 0;
}

// Worst case senario (Big O): Either target is at the end of the
// last division or doesn't exist in the array log(n) times.
// O(log n)

// Best case senario (Big Omega): Target element is at the midpoint
// of the array and it only runs once.
// Omega(1)
