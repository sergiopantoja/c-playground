#include <stdio.h>
#include <ctype.h>

#define BINS    26   /* one bin for each alphabetic character */
#define BARLEN  100  /* max length of histogram bar */

int main()
{
  // start counting word length
  int c, i, j, occurances, bars;
  int total = 0;
  int data[BINS];

  for (i = 0; i < BINS; i++)
    data[i] = 0;

  while ((c = getchar()) != EOF) {
    if (isalpha(c)) {
      total++;

      c = toupper(c);
      data[c-'A']++; /* A is 0, B is 1, C is 2, etc. */
    }
  }

  // print histogram
  printf("RESULTS\n");

  for (i = 'A'; i <= 'Z'; i++) {
    occurances = data[i-'A'];

    if (occurances > 0) {
      printf("%c: ", i);
      bars = (occurances*1.0) / (total*1.0) * BARLEN;
      for (j = 0; j < bars; j++)
        printf("=");
      printf(" %d occurances\n", occurances);
    }
  }

  return 0;
}
