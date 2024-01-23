#include <stdio.h>
#include <stdlib.h>
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

void itob(int n, char s[], int b) {
  if (b < 2 || b > 36) {
    printf("Base %d is not supported. Exiting...\n", b);
    exit(EXIT_FAILURE);
  }

  int i = 0;
  int sign = n < 0 ? -1 : 1;

  do {
    int digit = abs(n % b);
    s[i++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';

  } while ((n /= b) != 0);

  if (sign < 0) {
    s[i++] = '-';
  }

  s[i] = '\0';
  reverse(s);
}

int main() {
  char buffer[20]; // Adjust the size as needed
  int number, base;

  printf("Enter an integer: ");
  if (scanf("%d", &number) != 1) {
    printf("Invalid input. Exiting...\n");
    return 1;
  }

  printf("Enter the base (between 2 and 36): ");
  if (scanf("%d", &base) != 1 || base < 2 || base > 36) {
    printf("Invalid base. Exiting...\n");
    return 1;
  }

  itob(number, buffer, base);

  printf("%d in base %d: %s\n", number, base, buffer);

  return 0;
}
