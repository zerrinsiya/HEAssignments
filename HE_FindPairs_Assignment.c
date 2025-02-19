#include <stdio.h>
#include <stdlib.h>

#define MAXN 500000

long long findPairs(int *a, int n)
{
    long long count = 0;
    long long *diff = (long long *)calloc(2 * MAXN + 1, sizeof(long long));
    int offset = MAXN;

    for (int i = 1; i <= n; ++i)
    {
        long long val = (long long)a[i] - i;
        count += diff[val + offset];
        diff[val + offset]++;
    }

    free(diff);
    return count * 2;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
    }

    long long result = findPairs(a, n);
    printf("%lld\n", result);

    free(a);
    return 0;
}
