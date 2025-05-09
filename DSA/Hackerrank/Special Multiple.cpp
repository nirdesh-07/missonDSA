#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


long nine_zero(int n)
{
    for (int i = 1; ; ++i)
    {
        long multiple = 0;
        long chiffre = 9;
        for (int j = i; j != 0; j = j >> 1)
        {
            if (j & 1) multiple += chiffre;
            chiffre *= 10;
        }

        if (multiple % n == 0) return multiple;
    }
}

int main()
{
    int t, n;

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        printf("%ld\n", nine_zero(n));
    }

    return 0;
}