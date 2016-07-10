#include <stdio.h>

int main() {
    /* code */
    char c, prev;
    while ((c = getchar()) != EOF) {
        if (c == ' ' && prev == ' ')
            ;
        else
            putchar(c);
        prev = c;
    }

    return 0;
}
