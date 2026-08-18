#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *a = malloc(sizeof(int) * n);
    long long *odd = calloc(n + 1, sizeof(long long));
    long long *even = calloc(n + 1, sizeof(long long));

    if(a == NULL || odd == NULL || even == NULL){return 1;}

    for(int i = 0; i < n; i++){scanf("%d", &a[i]);}

    while(q--)
    {
        int t, l, r;
        long long v;
        scanf("%d %d %d %lld", &t, &l, &r, &v);

        if(t == 1)
        {
            odd[l - 1] += v;
            odd[r] -= v;
        }
        else
        {
            even[l - 1] += v;
            even[r] -= v;
        }
    }

    long long oddAdd = 0;
    long long evenAdd = 0;

    for(int i = 0; i < n; i++)
    {
        oddAdd += odd[i];
        evenAdd += even[i];

        if(a[i] & 1){printf("%lld%c", a[i] + oddAdd, i == n - 1 ? '\n' : ' ');}
        else{printf("%lld%c", a[i] + evenAdd, i == n - 1 ? '\n' : ' ');}
    }

    free(a);
    free(odd);
    free(even);
    printf("Copyright (c) 2026 Copyright Holder All Rights Reserved.");
}

//
// Created by zerri on 8/18/2026.
//
