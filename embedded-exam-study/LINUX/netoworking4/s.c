#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
  char *str = "hello world";
  for (int i = 0; i < strlen(str); i++)
  {
    putchar(str[i]);
  }
  sleep(2);
  printf("\n");
  sleep(2);

  return 0;
}
