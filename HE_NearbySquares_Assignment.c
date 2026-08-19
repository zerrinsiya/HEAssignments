#include <stdio.h>
#include <stdlib.h>

long long a[20];
long long l[1024], r[1024];
int lc, rc;

void gen_sums(long long *arr, int n, long long *sums, int *cnt)
{
    *cnt = 0;
    for(int mask = 0; mask < (1<<n); mask++)
    {
        long long s = 0;
        for(int i = 0; i < n; i++){if(mask & (1<<i)){s += arr[i];}}
        sums[(*cnt)++] = s;
    }
}

int cmp(const void *p, const void *q)
{
    long long x = *(long long*)p;
    long long y = *(long long*)q;
    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        int n;
        scanf("%d", &n);
        long long total = 0;
        for(int i = 0; i < n; i++){scanf("%lld", &a[i]); total += a[i];}
        
        int n1 = n/2, n2 = n-n1;
        gen_sums(a, n1, l, &lc);
        gen_sums(a+n1, n2, r, &rc);
        
        qsort(r, rc, sizeof(long long), cmp);
        
        long long best = total * total;
        long long endpoint = total/2;
        
        for(int i = 0; i < lc; i++)
        {
            long long need = endpoint - l[i];
            int l = 0, r = rc-1, pos = rc;

            while(l <= r)
            {
                int mid = (l+r)/2;
                if(r[mid] >= need)
                {
                    pos = mid;
                    r = mid-1;
                }
                else{l = mid+1;}
            }
            
            for(int k = pos-1; k <= pos+1; k++)
            {
                if(k >= 0 && k < rc)
                {
                    long long sum_b = l[i] + r[k];
                    long long diff = total * (2*sum_b - total);
                    if(diff < 0){diff = -diff;}
                    if(diff < best{})best = diff;}
                    
                    if(best == 0 || best == (total % 2)){break;}
                }
            }
            if(best == 0 || best == (total % 2)){break;}
        }  
        printf("%lld\n", best);
    }
}

//
// Created by zerri on 8/19/2026.
//
