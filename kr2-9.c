#include <stdio.h>
#include <string.h>

unsigned getbits(unsigned x, int p, int n);
const char *byte_to_binary(int x);

const char *byte_to_binary(int x)
{
    static char b[20];
    b[0] = '\0';

    int z;
    for (z = 512; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p+1-n)) & ~(~0 << n);
}

int main(void)
{
    unsigned z, a;
    z = 0b0110010100;
    a = getbits(z, 8, 5);

    printf("%s\n", byte_to_binary(z));
    printf("%s\n", byte_to_binary(a));

    return 0;
}
