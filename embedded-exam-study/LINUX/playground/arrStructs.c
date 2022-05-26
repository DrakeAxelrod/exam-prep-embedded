#include <stdio.h>
#include <stdlib.h>

typedef struct Obj
{
  int n;
} O;

int n = 0;

O newO() {
  O o;
  o.n = n;
  n++;
  return o;
}
int main()
{
  O arr[10];
  for (int i = 0; i < 10; i++)
  {
    arr[i] = newO();
  }
  for (int i = 0; i < 10; i++) {
    printf("%d", arr[i].n);
  }
  return 0;
}
