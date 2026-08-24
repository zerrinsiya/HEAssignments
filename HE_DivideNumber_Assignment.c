#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

int mcqueenRead()
{
    int x = 0;
    int c = getchar();
    while(c < '0' || c > '9'){c = getchar();}
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

int f[1000];
int fCount = 0;

void fFinder(int n)
{
    fCount = 0;
    int limit = (int)sqrt(n);

    for(int i = 1; i <= limit; i++)
    {
        if(n % i == 0)
        {
            if(n / i == i)
            {
                f[fCount++] = i;
            }
            else
            {
                f[fCount++] = n / i;
                f[fCount++] = i;
            }
        }
    }
}

long long productFinder(int n)
{
    long long product = -1;
    int s = fCount;

    for(int i = 0; i < s; i++)
    {
        for(int j = 0; j < s; j++)
        {
            for(int k = 0; k < s; k++)
            {
                for(int l = 0; l < s; l++)
                {
                    int s = f[i] + f[j] + f[k] + f[l];
                    if(s == n)
                    {
                        long long p = (long long)f[i] * f[j] * f[k] * f[l];
                        if(p > product){product = p;}
                    }
                }
            }
        }
    }
    return product;
}

int main()
{
    int t = mcqueenRead();

    while(t--)
    {
        int n = mcqueenRead();
        fFinder(n);
        printf("%lld\n", productFinder(n));
    }
}

//
// Created by zerri on 8/24/2026.
//