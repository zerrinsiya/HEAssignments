#include<stdio.h>

#define mod 1000000007u

unsigned mcqueenRead()
{
    unsigned x = 0;
    int c = getchar();
    while(c < '0' || c > '9'){c = getchar();}
    while(c >= '0' && c <= '9')
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    return x;
}

void mcqueenWrite(unsigned x)
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

unsigned power(unsigned b, unsigned e)
{
    unsigned r = 1;
    for(; e; e >>= 1)
    {
        if(e & 1){r = r * (long long unsigned)b % mod;}
        b = b * (long long unsigned)b % mod;
    }
    return r;
}

unsigned geomSum(unsigned b, unsigned e, unsigned x)
{
    if(e < 2){return e * x;}
    unsigned r = 1, s = b, k = 1u << 31;
    while(!(k & e)){k >>= 1;}
    for(; k >>= 1;)
    {
        r = r * (long long unsigned)(b + 1) % mod;
        b = b * (long long unsigned)b % mod;
        if(e & k)
        {
            if((r += b) >= mod){r -= mod;}
            b = b * (long long unsigned)s % mod;
        }
    }
    return r * (long long unsigned)x % mod;
}

unsigned L[64], R[64], PL[64], E;

unsigned prefixVal(unsigned n, unsigned s)
{
    if(!n){return 0;}
    if(n < L[s])
    {
        if(s == E){return power(2, n - 1);}
        else{return prefixVal(n, s + 1);}
    }
    return (geomSum(PL[s], n / L[s], R[s]) * (long long unsigned)power(2, n % L[s]) + prefixVal(n % L[s], s)) % mod;
}

void build(unsigned a, unsigned b, unsigned s)
{
    L[s] = a;
    PL[s] = power(2, a);
    if(a % b)
    {
        build(b, a % b, s + 1);
        R[s] = prefixVal(a, s + 1);
    }
    else
    {
        E = s;
        R[s] = power(2, a - 1);
    }
}

int main()
{
    unsigned t = mcqueenRead();
    while(t--)
    {
        unsigned x = mcqueenRead();
        unsigned y = mcqueenRead();
        build(x, y, 0);
        mcqueenWrite(R[0]);
    }
    return 0;
}

//
// Created by zerrinsiya on 17/09/2026.
//
