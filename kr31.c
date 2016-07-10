#include <stdio.h>

int binsearch(int x, int v[], int n);

int binsearch2(int x, int v[], int n);

/* binary search, find x in v[], sorted in increasing order */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1; /*no match */
}

int binsearch2(int x, int v[], int n) {
    int low, high, mid;
    low = 0;
    high = n - 1;
    mid = (low+high) / 2;
    while (low <= high && x != v[mid]) {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
        mid = (low+high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

int main() {
    int v[] = {1, 2, 3, 4, 7, 9, 10, 11, 23, 25, 27, 28};
    int n;
    printf("size of v, %d\n", sizeof(v));
    printf("size of int, %d\n", sizeof(int));
    printf("length of v should be 12, %d\n", (sizeof(v) / sizeof(int)));
    n = sizeof(v) / sizeof(int);
    printf("7 should be index 4, binsearch gives, %d\n", binsearch(7, v, n));
    printf("7 should be index 4, binsearch2 gives, %d\n", binsearch2(7, v, n));
    printf("21 should be absent, binsearch gives, %d\n", binsearch(21, v, n));
    printf("21 should be absent, binsearch2 gives, %d\n", binsearch2(21, v, n));
}
