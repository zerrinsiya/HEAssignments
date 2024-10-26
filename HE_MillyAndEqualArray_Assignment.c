#include <stdio.h>

int reduce(int num, int x, int y, int z)
{
    while (num % x == 0) num /= x;
    while (num % y == 0) num /= y;
    while (num % z == 0) num /= z;
    return num;
}

int main()
{
    int t;

    scanf("%d", &t);

    while(t--)
    {
        int n, x, y, z;
        scanf("%d %d %d %d", &n, &x, &y, &z);

        int a[n];

        for(int i = n; i--;)
        {
            scanf("%d", &a[i]);
            a[i] = reduce(a[i], x, y, z);
        }

        int target = a[0];
        int possible = 1;

        for (int i = n; i--;)
        {
            if (a[i] != target)
            {possible = 0; break;}
        }

        if(possible) {printf("She can\n");}
        else {printf("She can't\n");}
    }
    return 0;
}


// Created by zerri on 10/26/2024.

