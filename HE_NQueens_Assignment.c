#include<stdio.h>
#include<stdbool.h>
#include<string.h>

#define maxN 10

bool checkAndPlaceQ(int row, int n, int board[][maxN], bool cl[], bool d1[], bool d2[])
{
    if(row == n){return true;}

    for(int clPos = n; clPos--;)
    {
        if(!cl[clPos] && !d1[row - clPos + n] && !d2[row + clPos])
        {
            board[row][clPos] = 1;
            cl[clPos] = true;
            d1[row - clPos + n] = true;
            d2[row + clPos] = true;

            if(checkAndPlaceQ(row + 1, n, board, cl, d1, d2)){return true;}

            board[row][clPos] = 0;
            cl[clPos] = false;
            d1[row - clPos + n] = false;
            d2[row + clPos] = false;
        }
    }
    return false;
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    if(n == 2 || n == 3)
    {
        printf("Not possible\n");
        return 0;
    }

    int board[maxN][maxN];
    bool cl[maxN];
    bool d1[2 * maxN];
    bool d2[2 * maxN];
    memset(board, 0, sizeof(board));
    memset(cl, 0, sizeof(cl));
    memset(d1, 0, sizeof(d1));
    memset(d2, 0, sizeof(d2));

    if(checkAndPlaceQ(0, n, board, cl, d1, d2))
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = n; j--;)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
    }
    else{printf("Not possible\n");}
}

//
// Created by zerri on 8/22/2026.
//
