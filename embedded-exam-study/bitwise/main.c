#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

void to_bin(byte b) {
  int binary[8];
  for (int n = 0; n < 8; n++)
  {
    binary[7 - n] = (b >> n) & 1;
  }
  for (int n = 0; n < 8; n++)
    printf("%d", binary[n]);
  printf("\n");
}

void to_hex(byte b)
{
  printf("0x%X", b);
  // int binary[8];
  // for (int n = 0; n < 8; n++)
  // {
  //   binary[7 - n] = (b >> n) & 1;
  // }
  // for (int n = 0; n < 8; n++)
  //   printf("%d", binary[n]);
  // printf("\n");
}

int main(int argc, char const *argv[])
{
  byte b = 100;
  to_hex(b);
  // printf("%d", b);
  return 0;
}
