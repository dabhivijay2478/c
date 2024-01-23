#include <ctype.h> // Include ctype.h for the isupper and tolower functions
#include <stdio.h>
#include <string.h>

// Function to remove characters from s1 that are present in s2
void squeeze(char s1[], char s2[]) {
  int i, j, k;
  int contains = 0;

  for (i = j = 0; s1[i] != '\0'; i++) {
    // Convert the current character in s1 to lowercase
    char currentChar = tolower(s1[i]);

    // Check if the current character in s1 is present in s2
    for (k = 0; s2[k] != '\0'; k++) {
      if (currentChar == tolower(s2[k])) {
        contains = 1;
        break;
      }
    }

    // If the character is not present in s2, add it to the result
    if (!contains) {
      s1[j++] = s1[i];
    }

    contains = 0; // Reset the flag for the next iteration
  }

  s1[j] = '\0'; // Null-terminate the resulting string

  // If no characters matched for squeezing, display a message
  if (j == 0) {
    printf("No matching characters found for squeezing.\n");
  }
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

  // Validate input strings for uppercase and lowercase letters
  for (int i = 0; s1[i] != '\0'; i++) {
    if (!isupper(s1[i]) && !islower(s1[i])) {
      printf(
          "Invalid character in s1. Please enter only letters. Exiting...\n");
      return 1;
    }
  }

  for (int i = 0; s2[i] != '\0'; i++) {
    if (!isupper(s2[i]) && !islower(s2[i])) {
      printf(
          "Invalid character in s2. Please enter only letters. Exiting...\n");
      return 1;
    }
  }

  // Apply the squeeze function and print the result
  squeeze(s1, s2);
  printf("Result after squeezing: %s\n", s1);

  return 0;
}
