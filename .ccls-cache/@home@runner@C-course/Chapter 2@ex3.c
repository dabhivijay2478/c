#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool isValidHexChar(char c) {
  return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') ||
          (c >= 'A' && c <= 'F'));
}

bool isValidHexNumber(char s[]) {
  int startIndex = 0;

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    startIndex = 2;
  }

  for (int i = startIndex; s[i] != '\0'; i++) {
    if (!isValidHexChar(s[i])) {
      return false; // Invalid hexadecimal character found
    }
  }

  return true; // Input is a valid hexadecimal number
}

int htoi(char s[]) {
  int value = 0;
  int startIndex = 0;

  if (!isValidHexNumber(s)) {
    printf("Invalid hexadecimal number. Exiting...\n");
    return -1; // Return a special value to indicate error
  }

  if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
    startIndex = 2;
  }

  for (int i = startIndex; s[i] != '\0'; i++) {
    value = value * 16;
    if (s[i] >= '0' && s[i] <= '9') {
      value += s[i] - '0';
    } else if (s[i] >= 'a' && s[i] <= 'f') {
      value += 10 + s[i] - 'a';
    } else if (s[i] >= 'A' && s[i] <= 'F') {
      value += 10 + s[i] - 'A';
    }
  }

  return value;
}

int main() {
  char input[10];
  printf("Enter a hexadecimal number: ");

  if (scanf("%9s", input) != 1) {
    printf("Error reading input. Exiting...\n");
    return 1;
  }

  printf("Equivalent integer value: %d\n", htoi(input));
  return 0;
}
