#include<stdio.h>
int main()
{
  int input = 0;
  int product = 1;
  scanf("%d", &input);
  for (int changer = 1; changer < input + 1; changer++)
  {
    product *= changer;
  }
  printf("%d \n",product);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
