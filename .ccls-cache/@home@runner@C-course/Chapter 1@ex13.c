#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 20

int main() {
    int c, state, length;
    int word_length[MAX_LENGTH];

    state = OUT;
    length = 0;
    for (int i = 0; i < MAX_LENGTH; i++) {
        word_length[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (length > 0 && length < MAX_LENGTH) {
                word_length[length]++;
            }
            length = 0;
        } else if (state == OUT) {
            state = IN;
            length = 1;
        } else {
            length++;
        }
    }

    for (int i = 1; i < MAX_LENGTH; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < word_length[i]; j++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}