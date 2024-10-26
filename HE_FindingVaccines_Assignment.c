#include<stdio.h>
int RNAvG = 0;
int RNAvC = 0;
int RNAvaUnits = 0;
int Count = 0;
int MC = 0;
int RNAvIVC(int G, int C)
{
  int x = (G * RNAvC) + (C * RNAvG);
  if(x >= RNAvaUnits){RNAvaUnits = x; MC = Count; return 0;}
}
int GuanineAndCytosineCounter(int m, int flag)
{
  char x;
  int G = 0, C = 0;
  for (int changer = 0; changer < m + 1; changer++)
  {
    scanf("%c", &x);
    if(x == 'G'){G++;}
    if(x == 'C'){C++;}
  }
  if(flag == 1){RNAvG = G; RNAvC = C; return 0;}
  else{Count++; return RNAvIVC(G, C);}
}
int main()
{
  int n = 0, m = 0;
  scanf("%d", &n);
  n += 1;
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &m);
    GuanineAndCytosineCounter(m, i == 0 ? 1 : 0);
  }
  printf("%d \n",MC);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
