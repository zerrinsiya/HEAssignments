#include<stdio.h>
int main()
 {
  int t = 0;
	scanf("%d", &t);
  while(t--)
  {
    int c0, c1, c2, c3;
		scanf("%d",&c0);
		scanf("%d",&c1);
		scanf("%d",&c2);
		scanf("%d",&c3);
    int ar[4][4] = {0};
    ar[0][0] = c0;
    ar[0][1] = c1;
    ar[1][0] = c2;
    ar[1][1] = c3;
    int temp1[8], temp2[8];
    for(int i = 0; i < 8; i++)
    {
      for(int x = 0; x < 2; x++)
      {
        for(int y = 0; y <2 ; y++)
        {
          for(int z = 0; z < 2; z++)
          {
            temp1[i] = ar[ar[x][y]][z];
            i++;
          }
        }
      }
    }
    for(int i = 0; i < 8; i++)
    {
      for(int x = 0; x < 2; x++)
      {
        for(int y = 0; y < 2; y++)
        {
          for(int z = 0; z < 2; z++)
          {
            temp2[i] = ar[x][ar[y][z]];
            i++;
          }
        }
      }
    }
    int flag = 0;
    for(int i = 0; i < 8; i++)
    {
      if(temp1[i] != temp2[i])
      {
        flag = 1;
        break;
      }
    }
    if(flag)
      printf("No\n");
    else
      printf("Yes\n");
    }
    printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
  return 0;
}
