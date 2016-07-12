/* K&R C exercise 4-13, recursive string reverse. */

#include <stdio.h>
#define MAXLINE 1024

int getline(char s[], int max);
void reverse(char s[]);

void reverse(char s[])
{
    static int i = 0, len;

    if (s[i]) {
        int c = s[i++];
        reverse(s);
        s[len-i] = c;
        i--;
    }
    else {
        len = i;
    }
}

int getline(char s[], int max) {
    int c, i;

    for(i=0; i < max-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
         ++i;
    }
    s[i] = '\0';
    return i;
}

int main() {
    int len, i;
    char line[MAXLINE], longest[MAXLINE];

    while ((len = getline(line, MAXLINE)) != 0) {
        if (len > 1) {
            reverse(line);
            printf("%s\n", line);
        }
    }
    return 0;
}
