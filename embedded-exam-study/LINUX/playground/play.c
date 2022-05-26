#include <stdio.h>



void failmut(char *s)
{
  *s = "hello world";
}

void mut(char **s)
{
  **s = "hello world";
}

int main(int argc, char const *argv[])
{
  char *s = "nnnnnnnnnnn\0";
  mut(&s);

  printf("%s\n", s);

  /* code */
  return 0;
}