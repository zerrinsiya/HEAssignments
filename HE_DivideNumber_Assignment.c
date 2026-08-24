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
long long pairProd[80005];
int pairExists[80005];

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
    int s = fCount;

    for(int i = 0; i <= n; i++)
    {
        pairExists[i] = 0;
        pairProd[i] = 0;
    }

    for(int i = s; i--;)
    {
        int a = f[i];
        for(int j = s; j--;)
        {
            int b = f[j];
            int sum = a + b;
            long long prod = (long long)a * b;
            if(prod > pairProd[sum])
            {
                pairProd[sum] = prod;
                pairExists[sum] = 1;
            }
        }
    }

    long long product = -1;
    for(int sum = 2; sum <= n - 2; sum++)
    {
        if(!pairExists[sum]){continue;}
        int rem = n - sum;
        if(pairExists[rem])
        {
            long long p = pairProd[sum] * pairProd[rem];
            if(p > product){product = p;}
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
