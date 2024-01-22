#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    int contains = 0;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                contains = 1;
                break;
            }  
        }
        if (!contains) {
            s1[j++] = s1[i];
        }
        contains = 0;
    }
    s1[j] = '\0';
}
int main() {
    char s1[100], s2[100];
    printf("Enter string s1: ");
    scanf("%s", s1);
    printf("Enter string s2: ");
    scanf("%s", s2);
    squeeze(s1, s2);
    printf("Result after squeezing: %s\n", s1);
    return 0;
}