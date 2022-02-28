#include <stdio.h>

int main(int argc, char const *argv[])
{
  #ifdef _WIN32
    printf("You have Windows Operating System");
  #endif
  return 0;
}
