#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MOD 1000000007LL

int *sP;
int sPCnt = 0;
long long pV;

void sieve(int P)
{
    char *isP = (char*)malloc((P + 1) * sizeof(char));
    for(int i = 0; i <= P; i++){isP[i] = 1;}
    isP[0] = isP[1] = 0;
    for(int i = 2; i * i <= P; i++)
    {
        if(isP[i]){for(int j = i * i; j <= P; j += i){isP[j] = 0;}}
    }
    for(int i = 2; i <= P; i++){if(isP[i]){sPCnt++;}}
    sP = (int*)malloc(sPCnt * sizeof(int));
    int idx = 0;
    for(int i = 2; i <= P; i++){if(isP[i]){sP[idx++] = i;}}
    free(isP);
}

long long dfsCnt(int pos, int t, long long cur, int L)
{
    if(pos == t){return 1;}
    long long res = 0;
    int isC = ( (L % 2 == 1) && (pos == t-1) );
    if(isC)
    {
        for(int i = 0; i < sPCnt; i++)
        {
            int p = sP[i];
            if(p > pV / cur){break;}
            res += dfsCnt(pos + 1, t, cur * p, L);
            if(res >= MOD){res -= MOD;}
        }
    }
    else
    {
        for(int i = 0; i < sPCnt; i++)
        {
            long long p2 = (long long)sP[i] * (long long)sP[i];
            if(p2 > pV / cur){break;}
            res += dfsCnt(pos+1, t, cur * p2, L);
            if(res >= MOD){res -= MOD;}
        }
    }
    return res % MOD;
}

int main()
{
    int Q;
    if(scanf("%lld", &pV) != 1) return 0;
    if(scanf("%d", &Q) != 1) return 0;
    int *qArr = (int*)malloc(Q * sizeof(int));
    for(int i = 0; i < Q; i++){scanf("%d", &qArr[i]);}

    if(pV < 2)
    {
        for(int i = 0; i < Q; i++)
        {
            printf("0");
            if(i + 1 < Q){printf(" ");}
        }
        printf("\n");
        return 0;
    }
    sieve((int)pV);

    int lMax = 0;
    long long p2 = 1;
    while(p2 * 2 <= pV)
    {
        p2 *= 2;
        lMax++;
    }
    lMax = 0;
    long long p2tmp = 1;
    while(p2tmp <= pV)
    {
        lMax++;
        p2tmp <<= 1;
    }
    lMax--;
    if(lMax < 1){lMax = 0;}

    if(lMax == 0)
    {
        for(int i = 0; i < Q; i++)
        {
            printf("0");
            if(i + 1 < Q){printf(" ");}
        }
        printf("\n");
        return 0;
    }

    long long *cnts = (long long*)calloc(lMax+1, sizeof(long long));
    for(int L = 1; L <= lMax; L++)
    {
        int t = (L + 1) / 2;
        cnts[L] = dfsCnt(0, t, 1LL, L) % MOD;
    }

    long long *pref = (long long*)calloc(lMax+1, sizeof(long long));
    long long acc = 0;
    for(int L = 1; L <= lMax; L++)
    {
        acc += cnts[L];
        if(acc >= MOD){acc -= MOD;}
        pref[L] = acc;
    }

    for(int i = 0; i < Q; i++)
    {
        int N = qArr[i];
        long long ans = 0;
        if(N >= lMax){ans = pref[lMax];}
        else if(N >= 1){ans = pref[N];}
        else{ans = 0;}
        printf("%lld", ans % MOD);
        if(i + 1 < Q){printf(" ");}
    }
    printf("\n");

    free(sP);
    free(qArr);
    free(cnts);
    free(pref);
    return 0;
}

//
// Created by zerri on 8/19/2026.
//
