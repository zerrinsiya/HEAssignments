#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

long long mcqueenRead()
{
    long long x = 0;
    int c = getchar();
    while(c < '0' || c > '9'){c = getchar();}
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

void mcqueenWrite(long long x)
{
    if(x == 0)
    {
        putchar('0');
        putchar('\n');
        return;
    }

    char buffer[30];
    int idx = 0;
    while(x > 0)
    {
        buffer[idx++] = '0' + (x % 10);
        x /= 10;
    }

    while(idx > 0){putchar(buffer[--idx]);}
    putchar('\n');
}

long long totalSum(long long x){return (x * (x + 1)) / 2;}

long long solve(long long n, long long k)
{
    long long ans = 0;
    long long N = n;

    while(N > 0)
    {
        long long total = totalSum(N);
        long long div = N / k;
        long long multiples = totalSum(div) * k;
        ans += total - multiples;
        N = div;
    }
    return ans;
}

int main()
{
    int t = (int)mcqueenRead();
    while(t--)
    {
        long long n = mcqueenRead();
        long long k = mcqueenRead();
        mcqueenWrite(solve(n, k));
    }
}

//
// Created by zerri on 8/23/2026.
//
