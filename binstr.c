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


int main(void)
{
    unsigned z;
    z = 0b10010100;

    printf("%s\n", byte_to_binary(z));

    return 0;
}
