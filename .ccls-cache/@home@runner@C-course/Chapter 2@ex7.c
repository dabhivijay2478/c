#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main() {
  unsigned int x = 170;
  int p = 4;
  int n = 3;

  unsigned int result = invert(x, p, n);

  printf("Original value: %u\n", x);
  printf("Result after inverting bits at position %d for %d bits: %u\n", p, n,
         result);

  return 0;
}

unsigned int invert(unsigned int x, int p, int n) {
  unsigned int mask = ~(~0U << n) << (p - n + 1);

  return x ^ mask;
}
