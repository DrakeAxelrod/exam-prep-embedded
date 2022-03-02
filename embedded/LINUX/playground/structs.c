#include <stdio.h>
#include <stdlib.h>


typedef struct InnerObj {
  int n;
  char *str;
};
typedef struct Obj {
  int n;
  char *str;
  struct InnerObj o;
};


int main()
{
  struct InnerObj ino;
  ino.n = 11;
  ino.str = "I'm an Inner Object";
  struct Obj o; // neet to make it a pointer when init
  o.n = 10;
  o.str = "I'm and Object :D";
  o.o = ino;
  printf("======== Object ========\n");
  printf("%d\n", o.n);
  printf("%s\n", o.str);
  printf("===== Inner Object =====\n");
  printf("%d\n", o.o.n);
  printf("%s\n", o.o.str);
  return 0;
}
