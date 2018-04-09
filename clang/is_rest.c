#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

bool is_rest(string s);

int main(void)
{
  printf("%d\n", is_rest(""));
  return 0;
}

bool is_rest(string s)
{
  // strncmp(), as opposed to strcmp(),
  // takes 3 arguments, 3rd being how many
  // places it should check:
  if (strncmp(s, "\0", 1) == 0)
    return true;
  else
    return false;
}
