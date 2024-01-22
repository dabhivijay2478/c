#include <stdio.h>

int any(char s1[], char s2[]) {
    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    char s1[100], s2[100];
    printf("Enter string s1: ");
    scanf("%s", s1);
    printf("Enter string s2: ");
    scanf("%s", s2);
    int result = any(s1, s2);
    printf("Result: %d\n", result);
    return 0;
}