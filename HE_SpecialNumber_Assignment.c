#include<stdio.h>
int QuickSum(int a)
{
  int sum = 0;
  while(a > 0)
  {
    sum += (a % 10);
    a = (a / 10);
  }
  if(sum % 4 == 0){return 1;}
  else{return 0;}
}
int main()
{
  int n = 0, a = 0, flag = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a);
    while(1 > 0)
    {
      flag = QuickSum(a);
      if(flag != 1){a++; flag = QuickSum(a);}
      else{printf("%d \n",a); break;}
    }
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
