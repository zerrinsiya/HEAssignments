#include<stdio.h>
int main()
{
  int x = 0, y = 0, z = 0, p = 0;
  scanf("%d:%d",&x,&y);
  int totalmin = 0;
  totalmin = (x * 60) + y;
  int res;
  res = totalmin * 11 / 720 + 1;
  printf("%d \n",res);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
