#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  return (x & ~(~(~0 << n) << (p + 1 - n))) | (y & ~(~0 << n)) << (p + 1 - n);
}

int main() {
  unsigned x, y;
  int p, n;
  printf("Enter x, p, n, and y: ");
  scanf("%u %d %d %u", &x, &p, &n, &y);
  unsigned result = setbits(x, p, n, y);
  printf("Result: %u\n", result);
  return 0;
}