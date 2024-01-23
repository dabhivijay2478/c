#include <ctype.h> // Include ctype.h for the tolower function
#include <stdio.h>

// Function to find the index of the first matching character in s1 and s2
int any(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++) {
    // Convert the current character in s1 to lowercase
    char currentChar = tolower(s1[i]);

    for (int j = 0; s2[j] != '\0'; j++) {
      // Convert the current character in s2 to lowercase
      char compareChar = tolower(s2[j]);

      if (currentChar == compareChar) {
        return i; // Return the index of the first matching character
      }
    }
  }
  return -1; // Return -1 if no matching character is found
}

int main() {
  char s1[100], s2[100];

  // Input validation: Ensure s1 is not too long
  printf("Enter string s1 (up to 99 characters): ");
  if (scanf("%99s", s1) != 1) {
    printf("Error reading input. Exiting...\n");
    return 1;
  }

  // Input validation: Ensure s2 is not too long
  printf("Enter string s2 (up to 99 characters): ");
  if (scanf("%99s", s2) != 1) {
    printf("Error reading input. Exiting...\n");
    return 1;
  }

  // Apply the any function and print the result
  int result = any(s1, s2);
  printf("Result: %d\n", result);

  return 0;
}
