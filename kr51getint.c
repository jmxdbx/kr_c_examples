/* K&R C, Exercise 5-1. */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100 /* buffer size for ungetch */
int getch(void);
void ungetch(int);
int getint(int *);

int buf[BUFSIZE];  /* buffer for ungetch */
int nbuf = 0;       /* next free position in buf */

int main(void)
{
    int ret;
    do {
        int num;
        printf("Enter an integer: ");
        ret = getint(&num);
        if (ret > 0)
            printf("You entered: %d\n", num);
    } while (ret > 0);

    if (ret == EOF)
        printf("EOF.");
    else
        printf("Bad input.");
    return 0;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch())) /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
			ungetch(sign == -1 ? '-' : '+');
			return 0;
		}
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10  * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int getch(void)
{
    return (nbuf > 0) ? buf[--nbuf] : getchar();
}

void ungetch(int c)
{
    if (nbuf < BUFSIZE)
        buf[nbuf++] = c;
    else
        printf("error: ungetch overflow\n");
}
