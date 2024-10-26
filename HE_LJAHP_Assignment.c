#include<stdio.h>
#include<stdlib.h>
int main()
{
  int b = 0, t = 0, g = 0, n;
  scanf("%d", &t);
  for (t = t; t--;)
  {
    scanf("%d", &n);
    scanf("%d %d", &b, &g);
    if(abs(b - g) > 1){printf("Little Jhool wins!\n"); continue;}
    else{printf("The teacher wins!\n"); continue;}
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
