#include <stdio.h>
int main() {
  int x = 10;
  x += (x++) + (++x) + x;
  printf("%d", x);
  return 0;
}