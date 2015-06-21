#include <stdio.h>

#define OUTWORD  0
#define INWORD   1
#define BARLEN   100

int main()
{
  // start counting word length
  int c, i, total, bars;
  int state = OUTWORD;
  int length = 0;
  int data[4]; /* the bins are 1-3 letters, 4-6 letters, 7-9 letters, 10+ letters */

  for (i = 0; i < 4; i++)
    data[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == INWORD) {
        // word ended! increment the proper histogram "bin" based on the length
        total++;

        if (length >= 10)
          data[3]++;
        else if (length >= 7)
          data[2]++;
        else if (length >= 4)
          data[1]++;
        else if (length >= 1)
          data[0]++;

        length = 0;
      }

      state = OUTWORD;
    } else {
      length++;
      state = INWORD;
    }
  }

  // print histogram
  printf("RESULTS\n");

  printf("1-3: ");
  bars = (data[0]*1.0) / (total*1.0) * BARLEN;
  for (i = 0; i < bars; i++)
    printf("=");
  printf(" %d words\n", data[0]);

  printf("4-6: ");
  bars = (data[1]*1.0) / (total*1.0) * BARLEN;
  for (i = 0; i < bars; i++)
    printf("=");
  printf(" %d words\n", data[1]);

  printf("7-9: ");
  bars = (data[2]*1.0) / (total*1.0) * BARLEN;
  for (i = 0; i < bars; i++)
    printf("=");
  printf(" %d words\n", data[2]);

  printf("10+: ");
  bars = (data[3]*1.0) / (total*1.0) * BARLEN;
  for (i = 0; i < bars; i++)
    printf("=");
  printf(" %d words\n", data[3]);

  return 0;
}
