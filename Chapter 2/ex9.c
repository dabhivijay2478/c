#include <stdio.h>
int fasterBitCount(unsigned int x);
int main() {
  unsigned int number = 2605; 

  int count = fasterBitCount(number);

  printf("Number of set bits in %u: %d\n", number, count);

  return 0;
}

int fasterBitCount(unsigned int x) {
  int count = 0;

  while (x != 0) {
    x &= (x - 1);
    count++;
  }

  return count;
}
