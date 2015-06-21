#include <stdio.h>

#define  LOWER  0    /* lower limit of table */
#define  UPPER  300  /* upper limit */
#define  STEP   20   /* step size */

float to_celcius(float fahr);

/* Farenheit to celcius table. This implementation uses a function
 * to do the conversion. */
int main()
{
  int fahr;

  for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    printf("%3d %6.1f\n", fahr, to_celcius(fahr));

  return 0;
}

float to_celcius(float fahr)
{
  return (5.0/9.0) * (fahr-32.0);
}
