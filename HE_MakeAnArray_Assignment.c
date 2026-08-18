#include <stdio.h>
#include <stdlib.h>

int solve(int n, int* a)
{
    long long sum = 0;
    int max = 0;

    for(int i = n; i--;)
    {
        sum += a[i];
        if(a[i] > max){max = a[i];}
    }

    if(sum % (n - 1)){return -1;}

    long long operations = sum / (n - 1);
    if(operations < max){return -1;}

    return (int)operations;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(; t--;)
    {
        int n;
        scanf("%d", &n);
        int *a = malloc(sizeof(int) * n);

        for (int i = n; i--;){scanf("%d", &a[i]);}
        printf("%d\n", solve(n, a));

        free(a);
    }
    printf("\nCopyright (c) 2026 Copyright Holder All Rights Reserved.");
    return 0;
}

//
// Created by zerri on 8/18/2026.
//
