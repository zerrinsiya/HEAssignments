#include <stdio.h>
#include <stdlib.h>
#define mod 1000000007

static inline int popcount(unsigned int x){return __builtin_popcount(x);}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        long long odd = 0;
        long long even = 1;
        int xor = 0;
        long long dp = 0;

        for(int i = 0; i < n; i++)
        {
            int x;
            scanf("%d", &x);
            xor ^= x;

            if(popcount((unsigned int)xor) % 2 == 1)
            {
                dp = even;
                odd = (odd + dp) % mod;
            }
            else
            {
                dp = odd;
                even = (even + dp) % mod;
            }
        }
        printf("%lld\n", dp);
    }
}

//
// Created by zerri on 8/18/2026.
//
