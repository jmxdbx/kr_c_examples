#include <stdio.h>

int atoi(char s[]);
int lower(int c);

int atoi(char s[]) {
    int i, n;
    n= 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}

int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

int main() {

    char s[] = "5746";

    printf("5746 is %7d \n", atoi(s));

    printf("B is %d", lower('A'));

}
