#include<stdio.h>
int RoomDivider(int x ,int k)
{
  int sum = 0;
  if(x % k == 0){sum += x / k;}
  else{sum += (x / k) + 1;}
  return sum;
}
int main()
{
  int t = 0, n = 0, m = 0, k = 0, sum = 0;
  scanf("%d", &t);
  for (int i = 0; i < t; i++)
  {
    sum = 0;
    scanf("%d %d %d", &n, &m, &k);
    sum += RoomDivider(n, k);
    sum += RoomDivider(m, k);
    printf("%d \n",sum);
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
