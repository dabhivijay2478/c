#include <stdio.h>
#include <string.h>

int htoi(char s[]) {
    int value = 0;
    int startIndex = 0;
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
    if (scanf("%s", input) != 1) {
        printf("Error reading input. Exiting...\n");
        return 1;
    }
    printf("Equivalent integer value: %d\n", htoi(input));
    return 0;
}
