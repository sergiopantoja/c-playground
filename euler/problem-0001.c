#include <stdio.h>

#define MAX  1000
#define MUL1 3
#define MUL2 5

int main()
{
  int i;
  int result = 0;

  for (i = MUL1; i < MAX; i += MUL1)
    result += i;

  for (i = MUL2; i < MAX; i += MUL2)
    result += i;

  for (i = MUL1 * MUL2; i < MAX; i += MUL1 * MUL2)
    result -= i;

  printf("Result: %d\n", result);

  return 0;
}
