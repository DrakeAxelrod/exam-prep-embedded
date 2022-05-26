#include <stdio.h>


void x() {
  printf("invoked");
}
int main()
{
  void (*vp)();
  vp = &x;
  (*vp)();
  return 0;
}
