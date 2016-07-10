#include <stdio.h>
#include <string.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

const char *byte_to_binary(int x);

const char *byte_to_binary(int x)
{
    static char b[20];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned temp1;
    unsigned temp2;
    temp1 = (x >> (p+1-n)) & ~(~0 << n);
    temp2 = (y & (~0 << n));
    return temp1 | temp2;
}

int main(void)
{
    unsigned z, a, y;
    z = 0b10010100;
    y = 0b01110010;
    a = setbits(z, 4, 3, y);

    printf("%s\n", byte_to_binary(z));
    printf("%s\n", byte_to_binary(y));
    printf("%s\n", byte_to_binary(a));

    return 0;
}
