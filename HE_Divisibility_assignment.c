#include<stdio.h>
#include<stdlib.h>
int main()
{
  int size;
  scanf("%d",&size);
  int input[size];
  for(int changer = 0; changer < size;  changer++)
  {
    scanf("%d", &input[changer]);
  }
  if(input[size - 1] % 10 == 0)
  {
    printf("Yes \n");
  }
  else
  {
    printf("No \n");
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
