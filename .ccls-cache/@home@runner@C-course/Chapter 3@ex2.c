#include <stdio.h>

void escape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j++] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j++] = 't';
      break;
    // Add cases for other escape sequences as needed
    default:
      s[j++] = t[i];
      break;
    }
  }
  s[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j;
  for (i = j = 0; t[i] != '\0'; i++) {
    if (t[i] == '\\') {
      switch (t[++i]) {
      case 'n':
        s[j++] = '\n';
        break;
      case 't':
        s[j++] = '\t';
        break;
      // Add cases for other escape sequences as needed
      default:
        s[j++] = '\\';
        s[j++] = t[i];
        break;
      }
    } else {
      s[j++] = t[i];
    }
  }
  s[j] = '\0';
}

int main() {
  char original[] = "This is a text with\ttabs\nand newlines.";
  char escaped[2 * sizeof(original)]; // Twice the size to account for potential
                                      // escape sequences
  char unescaped[sizeof(original)];

  // Escape the original string
  escape(escaped, original);
  printf("Original: %s\n", original);
  printf("Escaped : %s\n", escaped);

  // Unescape the escaped string
  unescape(unescaped, escaped);
  printf("Unescaped: %s\n", unescaped);

  return 0;
}
