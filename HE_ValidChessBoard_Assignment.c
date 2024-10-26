#include<stdio.h>
int count = 0, x = 49, y = 48;
int checkColumn(int n, int m, int t[n][m], int a, int b)
{
  int l = 7;
  for (a = a; l--;)
  {
    a--;
    if(x == 48 && y == 49){x = 49; y = 48;}
    else if(x == 49 && y == 48){x = 48; y = 49;}
    if(t[a][b] == y && t[a][b - 1] == x && t[a][b - 2] == y && t[a][b - 3] == x && t[a][b - 4] == y && t[a][b - 5] == x && t[a][b - 6] == y && t[a][b - 7] == x){continue;}
    else{return 0;}
  }
  count++;
}

int check(int n, int m, int t[n][m])
{
  for (int c = n; c--;)
  {
    for (int i = m; i--;)
    {
      if((t[c][i] == 48 && t[c][i - 1] == 49 && t[c][i - 2] == 48 && t[c][i - 3] == 49 && t[c][i - 4] == 48 && t[c][i - 5] == 49 && t[c][i - 6] == 48 && t[c][i - 7] == 49) && ((i - 7 >= 0) && (c - 7 >= 0))){x = 49, y = 48; checkColumn(n, m, t, c, i);}
      else if((t[c][i] == 49 && t[c][i - 1] == 48 && t[c][i - 2] == 49 && t[c][i - 3] == 48 && t[c][i - 4] == 49 && t[c][i - 5] == 48 && t[c][i - 6] == 49 && t[c][i - 7] == 48) && ((i - 7 >= 0) && (c - 7 >= 0))){x = 48, y = 49; checkColumn(n, m, t, c, i);}
    }
  }
}

int main()
{
  int n = 0, m = 0, u = 0;
  scanf("%d %d\n", &n, &m);
  int t[n][m];
  for (int c = 0; c < n; c++)
  {
    scanf("\n");
    for (int i = 0; i < m; i++)
    {
      u = 0;
      scanf("%c", &u);
      if(u != 10){t[c][i] = u;}
    }
  }
  check(n, m, t);
  printf("%d \n", count);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
