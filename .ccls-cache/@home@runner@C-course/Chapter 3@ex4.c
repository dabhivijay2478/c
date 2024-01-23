#include <limits.h>
#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for abs
#include <string.h>

void reverse(char s[]) {
  int i, j;
  char temp;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
  }
}

void itoa(int n, char s[]) {
  int i, sign;

  sign = n;

  i = 0;
  do {
    s[i++] = abs(n % 10) + '0';
  } while ((n /= 10) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

int main() {
  char buffer[20]; // Adjust the size as needed
  int largestNegative = INT_MIN;

  itoa(largestNegative, buffer);

  printf("Largest Negative Number: %s\n", buffer);

  return 0;
}
