#include <stdio.h>

#define MAX 4000000

int main()
{
  int temp;
  int prev_term = 1;
  int curr_term = 1;
  int result = 0;

  while (curr_term < MAX) {
    if (curr_term % 2 == 0)
      result += curr_term;

    temp = curr_term;
    curr_term += prev_term;
    prev_term = temp;
  }

  printf("Result: %d\n", result);
  return 0;
}
