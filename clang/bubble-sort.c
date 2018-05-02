#include <stdio.h>
#include <stdbool.h>

int main(void)
{
  int j, k;
  int arr[10] = {3,6,7,9,1,4,10,5,2,8};
  int len = sizeof(arr) / sizeof(arr[0]);
  bool swapped = true;
  int count;

  while (swapped)
  {
    count = 0;

    for (j = 0; j < len - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int toSwitch = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = toSwitch;

        count++;
      }
    }

    if (count == 0)
    {
      swapped = false;
      len = 10;
    }
    else
    {
      len--;
    }
  }

  printf("Array has been bubble sorted!\n");
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
