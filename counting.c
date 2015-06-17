#include <stdio.h>

main()
{
  int c;
  long char_count = 0;
  long line_count = 0;

  while ((c = getchar()) != EOF) {
    char_count++;
    if (c == '\n')
      line_count++;
  }

  printf("%ld chars, %ld lines\n", char_count, line_count);
}
