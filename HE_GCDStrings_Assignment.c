#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

#define mod 1000000007LL

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

long long power(long long base, long long exp)
{
    long long result = 1;
    base %= mod;
    while(exp > 0)
    {
        if(exp & 1){result = (result * base) % mod;}
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long a)
{
    return power(a, mod - 2);
}

long long solve(long long x, long long y)
{
    long long origX = x;

    while(y != 0 && x % y != 0)
    {
        long long temp = x % y;
        x = y;
        y = temp;
    }

    long long L = x;
    long long k = origX / L;
    long long r = origX % L;

    long long v = power(2, L - 1);
    long long vr = (r > 0) ? power(2, r - 1) : 0;

    long long geomSum;

    if(k == 1)
    {
        geomSum = 1;
    }
    else
    {
        long long twoL = power(2, L);
        long long geomDen = (twoL - 1 + mod) % mod;

        if(geomDen == 0)
        {
            geomSum = k % mod;
        }
        else
        {
            long long twoLk = power(2, L * k);
            long long geomNum = (twoLk - 1 + mod) % mod;
            geomSum = (geomNum * modInverse(geomDen)) % mod;
        }
    }

    long long ans = (v * geomSum) % mod;
    ans = (ans * power(2, r)) % mod;
    ans = (ans + vr) % mod;

    return ans;
}

int main()
{
    int t = (int)mcqueenRead();

    while(t--)
    {
        long long x = mcqueenRead();
        long long y = mcqueenRead();
        mcqueenWrite(solve(x, y));
    }
}

//
// Created by zerrinsiya on 17/09/2026.
//
