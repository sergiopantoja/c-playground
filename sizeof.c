#include <stdio.h>

int main()
{
  printf("short:\t%lu bytes\n", sizeof(short));
  printf("char:\t%lu bytes\n", sizeof(char));
  printf("int:\t%lu bytes\n", sizeof(int));
  printf("long:\t%lu bytes\n", sizeof(long));
  printf("float:\t%lu bytes\n", sizeof(float));
  printf("double:\t%lu bytes\n", sizeof(double));

  return 0;
}
