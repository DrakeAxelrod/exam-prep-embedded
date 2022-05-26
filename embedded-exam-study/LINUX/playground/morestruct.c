#include <stdio.h>


typedef struct {
  
} S;

int main(int argc, char const *argv[])
{

  S *s;
  s = malloc(sizeof(S));
  free(s);
  /* code */
  return 0;
}
