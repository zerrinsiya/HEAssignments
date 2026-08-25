#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
#include<stdbool.h>
#include<math.h>

#define INF 1000000000

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

void mcqueenWrite(const char* s)
{
    while(*s){putchar(*s++);}
    putchar('\n');
}

int primeDivs[1000001][10];
int primeCount[1000001];

void findPrimes()
{
    for(int i = 2; i <= 1000000; i++)
    {
        if(primeCount[i] == 0)
        {
            for(int j = i; j <= 1000000; j += i)
            {
                primeDivs[j][primeCount[j]++] = i;
            }
        }
    }
}

int queue[100][3];
int front, rear;

void push(int pos, int parity, int steps)
{
    queue[rear][0] = pos;
    queue[rear][1] = parity;
    queue[rear][2] = steps;
    rear++;
}

int visited[40][2];
int evenDist[40];
int oddDist[40];

void reset()
{
    for(int i = 0; i < 40; i++)
    {
        evenDist[i] = INF;
        oddDist[i] = INF;
    }
    front = 0;
    rear = 0;
}

int canReach(int n, int a[], int m)
{
    reset();

    evenDist[0] = 0;
    push(0, 0, 0);

    while(front < rear)
    {
        int pos = queue[front][0];
        int parity = queue[front][1];
        int steps = queue[front][2];
        front++;

        if(steps > m){continue;}

        if(pos == n - 1)
        {
            if(parity == (m % 2))
            {
                return 1;
            }
        }

        int val = a[pos];
        int count = primeCount[val];

        for(int i = 0; i < count; i++)
        {
            int jump = primeDivs[val][i];

            int newPos = pos + jump;
            if(newPos < n)
            {
                int newParity = 1 - parity;
                int newSteps = steps + 1;
                if(newParity == 0)
                {
                    if(newSteps < evenDist[newPos])
                    {
                        evenDist[newPos] = newSteps;
                        push(newPos, newParity, newSteps);
                    }
                }
                else
                {
                    if(newSteps < oddDist[newPos])
                    {
                        oddDist[newPos] = newSteps;
                        push(newPos, newParity, newSteps);
                    }
                }
            }

            newPos = pos - jump;
            if(newPos >= 0)
            {
                int newParity = 1 - parity;
                int newSteps = steps + 1;
                if(newParity == 0)
                {
                    if(newSteps < evenDist[newPos])
                    {
                        evenDist[newPos] = newSteps;
                        push(newPos, newParity, newSteps);
                    }
                }
                else
                {
                    if(newSteps < oddDist[newPos])
                    {
                        oddDist[newPos] = newSteps;
                        push(newPos, newParity, newSteps);
                    }
                }
            }
        }
    }

    if(m % 2 == 0){return (evenDist[n - 1] <= m);}
    else{return (oddDist[n - 1] <= m);}
}

int main()
{
    findPrimes();
    int t = mcqueenRead();

    while(t--)
    {
        int n = mcqueenRead();
        int a[40];

        for(int i = 0; i < n; i++){a[i] = mcqueenRead();}
        int m = mcqueenRead();

        if(canReach(n, a, m)){mcqueenWrite("YES");}
        else{mcqueenWrite("NO");}
    }
}

//
// Created by zerri on 8/25/2026.
//
