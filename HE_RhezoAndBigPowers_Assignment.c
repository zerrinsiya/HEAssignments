#include <stdio.h>

#define ll long long
#define N 100005
#define MOD 1000000007LL

static inline ll mainExp(const char b[])
{
    ll expo = 0;
    for(int i = 0; b[i]; ++i){expo = (expo * 10 + b[i] - '0') % (MOD - 1);}
    return expo;
}

static inline ll powOp(ll x, ll n)
{
    ll s = 1;
    x %= MOD;

    for(; n; n >>= 1)
    {
        if(n & 1){s = (s * x) % MOD;}
        x = (x * x) % MOD;
    }
    return s;
}

int main(void)
{
    ll a;
    char b[N];
    scanf("%lld %100004s", &a, b);

    ll out = powOp(a, mainExp(b));
    printf("%lld\n", out);
    printf("Copyright (c) 2026 Copyright Holder All Rights Reserved.");
    return 0;
}

//
// Created by zerri on 8/17/2026.
//
