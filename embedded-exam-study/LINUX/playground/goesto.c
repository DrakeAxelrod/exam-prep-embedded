#include <stdio.h>
int main()
{
  int x = 10;
  while (x --> 0) // x goes to 0
  {
    printf("%d ", x);
  }
  printf("\n");

  int z = 0;
  while (z++ < 10) // x goes to 10
  {
    printf("%d ", z);
  }
  printf("\n");

  return 0;
}
