#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long long key;
    int count;
} Pair;

unsigned long long hash(long long key, unsigned long long size){return key % size;}

int main()
{
    int n;
    scanf("%d", &n);

    Pair *m = (Pair *)calloc(n, sizeof(Pair));
    unsigned long long size = n * 2;
    unsigned long long *hash_table = (unsigned long long *)calloc(size, sizeof(unsigned long long));
    int uniqueCount = 0;

    for(int i = 0; i < n; i++)
    {
        long long num;
        scanf("%lld", &num);
        unsigned long long index = hash(num, size);

        while(hash_table[index] != 0)
        {
            if(m[hash_table[index] - 1].key == num)
            {
                m[hash_table[index] - 1].count++;
                break;
            }

            index = (index + 1) % size;
        }

        if(hash_table[index] == 0)
        {
            m[uniqueCount].key = num;
            m[uniqueCount].count = 1;
            hash_table[index] = uniqueCount + 1;
            uniqueCount++;
        }
    }

    int cnt = 0, mx = 0;
    for(int i = 0; i < uniqueCount; i++)
    {
        if(m[i].count == mx){cnt++;}
        else if(m[i].count > mx){mx = m[i].count; cnt = 1;}
    }

    printf("%d\n", cnt);

    free(m);
    free(hash_table);
    return 0;
}
