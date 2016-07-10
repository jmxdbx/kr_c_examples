#include <stdio.h>

/* squeeze2: delete eacch character in s1 that is in s2*/

void squeeze2(char s1[], char s2[]);

int main()
{
    char s1[] = "antidisestablishmentarianism";
    char s2[] = "aie";
    squeeze2(s1, s2);
    printf("%s\n", s1);
}



void squeeze2(char s1[], char s2[])
{
    int i, j, k, dupe;
    k = 0;

    for (i = 0; s1[i] != '\0'; i++)
    {
        dupe = 0;
        for (j = 0; s2[j] != '\0' && !dupe; j++)
        {
            if (s1[i] == s2[j])
                dupe = 1;
        }
        if (!dupe)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
