#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>

bool palindromeCheck(int n)
{
    if(n == 0){return true;}

    int rev = 0;
    int temp = n;
    while(temp > 0)
    {
        rev = (rev << 1) | (temp & 1);
        temp >>= 1;
    }
    return rev == n;
}

int bitCount(int n)
{
    int bits = 0;
    while(n > 0)
    {
        bits++;
        n >>= 1;
    }
    return bits;
}

long long palindromeFlip(int pf, int totalBits, bool oddLen)
{
    long long pal = pf;
    int temp = (oddLen) ? pf >> 1 : pf;

    while(temp > 0)
    {
        pal = (pal << 1) | (temp & 1);
        temp >>= 1;
    }
    return pal;
}

long long minimum(long long a, long long b){return (a < b) ? a : b;}

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

void mcqueenWrite(int x)
{
    if(x == 0)
    {
        putchar('0');
        putchar('\n');
        return;
    }

    char buffer[20];
    int idx = 0;
    while(x > 0)
    {
        buffer[idx++] = '0' + (x % 10);
        x /= 10;
    }

    while(idx > 0){putchar(buffer[--idx]);}
    putchar('\n');
}

int opCount(int n)
{
    if(n == 0 || palindromeCheck(n)){return 0;}
    if(n == 2){return 1;}
    if(n == 3){return 0;}

    int bits = bitCount(n);
    int half = n >> (bits / 2);
    long long minDiff = LLONG_MAX;

    for(int off = -1; off <= 1; off++)
    {
        int pf = half + off;
        if(pf <= 0){continue;}

        long long pal = palindromeFlip(pf, bits, bits & 1);
        int pBit = bitCount((int)pal);

        if(pBit == bits || pBit == bits - 1)
        {
            long long diff = llabs((long long)n - pal);
            if(diff < minDiff){minDiff = diff;}
        }
    }

    long long allOnes = (1LL << bits) - 1;
    minDiff = minimum(minDiff, llabs((long long)n - allOnes));
    long long ends = (1LL << (bits - 1)) + 1;
    minDiff = minimum(minDiff, llabs((long long)n - ends));

    if(bits > 1)
    {
        long long lessBits = (1LL << (bits - 1)) - 1;
        minDiff = minimum(minDiff, llabs((long long)n - lessBits));

        long long lessEnds = (1LL << (bits - 2)) + 1;
        minDiff = minimum(minDiff, llabs((long long)n - lessEnds));
    }

    return (int)minDiff;
}

int main()
{
    int t = mcqueenRead();
    while(t--)
    {
        int n = mcqueenRead();
        mcqueenWrite(opCount(n));
    }
}

//
// Created by zerri on 8/22/2026.
//