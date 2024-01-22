#include <stdio.h>

void convertToLowercase(char *str);

int main() {
  // Example usage
  char uppercaseString[] = "VIJAY DABHI";
  printf("Original string: %s\n", uppercaseString);

  convertToLowercase(uppercaseString);

  printf("Lowercased string: %s\n", uppercaseString);

  return 0;
}

void convertToLowercase(char *str) {
  while (*str) {
    *str = (*str >= 'A' && *str <= 'Z') ? *str + 'a' - 'A' : *str;
    ++str;
  }
}
