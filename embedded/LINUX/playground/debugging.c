
#include <stdio.h>

#define WHERE fprintf(stderr, "[LOG]%s:%s:%d\n", __FILE__,__func__, __LINE__);

int main(int argc, char const *argv[])
{
  WHERE printf("hello world");
  return 0;
}
