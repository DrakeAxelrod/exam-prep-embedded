#include <stdio.h>
#include <stdlib.h>

typedef struct obj
{
  void *any;
} Obj;


Obj newO()
{
  Obj o;
  // o.any = 100;
  o.any = "hello";
  return o;
}
int main()
{
  Obj o = newO();
  void *vptr;
  vptr = &o;
  // printf("%d\n", o.any); // digit
  printf("%s\n", o.any); // string
  printf("%s\n", (*(Obj *)vptr).any); // casting the void pointer to Obj pointer then dereferencing the pointer then accessing .any (this is kind of cool but also fucked...)
  char *whatever;
  return 0;
}
// you can basically do whatever you want with void * :P
