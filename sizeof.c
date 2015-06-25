#include <stdio.h>

int main()
{
  printf("short:\t%lu bytes\n", sizeof(short));
  printf("char:\t%lu bytes\n", sizeof(char));
  printf("int:\t%lu bytes\n", sizeof(int));
  printf("long:\t%lu bytes\n", sizeof(long));
  printf("float:\t%lu bytes\n", sizeof(float));
  printf("double:\t%lu bytes\n", sizeof(double));
  printf("\npointers\n\n");
  printf("pointer to void:\t%lu bytes\n", sizeof(void *));
  printf("pointer to char:\t%lu bytes\n", sizeof(char *));
  printf("pointer to int: \t%lu bytes\n", sizeof(int *));
  printf("pointer to long:\t%lu bytes\n", sizeof(long *));

  return 0;
}
