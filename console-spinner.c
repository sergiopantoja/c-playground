#include <stdio.h>
#include <unistd.h>

main()
{
  int delay = 100000;

  while(1) {
    printf("\b/");
    usleep(delay);
    fflush(stdout);

    printf("\b\\");
    usleep(delay);
    fflush(stdout);
  }
}
