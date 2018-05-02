#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int i;
  int arr[10] = {88,6,74,9,32,1,2,54,7,8};
  int len = sizeof(arr) / sizeof(arr[0]);
  int target = 9;
  bool found = false;

  for (i = 0; i < len; i++)
  {
    if (arr[i] == target)
    {
      found = true;
      // Since target is found, end the loop.
      i = len;
    }
  }

  printf("Target: %i, ", target);

  if (found)
    printf("found.\n");
  else
    printf("not found.\n");

  return 0;
}

// Worst case senario (Big O): Target is not found so it
// has to iterate over all of the elements in the array.

// Best case senario (Big Omega): Target is the first
// number in the array.
