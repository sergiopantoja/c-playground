#include <stdio.h>

main()
{
  int c;
  int found_space = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (!found_space) {
        putchar(c);
      }
      found_space = 1;
    } else {
      putchar(c);
      found_space = 0;
    }
  }
}
