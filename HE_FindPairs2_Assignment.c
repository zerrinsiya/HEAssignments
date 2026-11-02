#include<stdio.h>
#include<stdlib.h>

#define MAX_N 100005

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

long long E[MAX_N];
long long O[MAX_N];
int eCount = 0;
int oCount = 0;

int compare(const void *a, const void *b)
{
    long long valA = *(long long*)a;
    long long valB = *(long long*)b;
    if(valA < valB){return -1;}
    if(valA > valB){return 1;}
    return 0;
}

int main()
{
    int n = (int)mcqueenRead();
    long long L = mcqueenRead();
    long long R = mcqueenRead();

    for(int i = 0; i < n; i++)
    {
        long long val = mcqueenRead();
        if(val % 2 == 0){E[eCount++] = val;}
        else{O[oCount++] = val;}
    }

    qsort(E, eCount, sizeof(long long), compare);
    qsort(O, oCount, sizeof(long long), compare);

    long long totalPairs = 0;

    if(eCount <= oCount)
    {
        for(int i = 0; i < eCount; i++)
        {
            long long x = E[i];
            long long targetMin = L - x;
            long long targetMax = R - x;
            int left = 0, right = oCount - 1;
            int startIdx = oCount;

            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(O[mid] >= targetMin)
                {
                    startIdx = mid;
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            left = 0;
            right = oCount - 1;
            int endIdx = -1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(O[mid] <= targetMax)
                {
                    endIdx = mid;
                    left = mid + 1;
                }
                else{right = mid - 1;}
            }

            if(startIdx <= endIdx){totalPairs += (endIdx - startIdx + 1);}
        }
    }
    else
    {
        for(int i = 0; i < oCount; i++)
        {
            long long x = O[i];
            long long targetMin = L - x;
            long long targetMax = R - x;

            int left = 0, right = eCount - 1;
            int startIdx = eCount;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(E[mid] >= targetMin)
                {
                    startIdx = mid;
                    right = mid - 1;
                }
                else{left = mid + 1;}
            }

            left = 0;
            right = eCount - 1;
            int endIdx = -1;
            while(left <= right)
            {
                int mid = left + (right - left) / 2;
                if(E[mid] <= targetMax)
                {
                    endIdx = mid;
                    left = mid + 1;
                }
                else{right = mid - 1;}
            }

            if(startIdx <= endIdx)
            {
                totalPairs += (endIdx - startIdx + 1);
            }
        }
    }

    mcqueenWrite(totalPairs);
}

//
// Created by zerrinsiya on 02/11/2026.
//
