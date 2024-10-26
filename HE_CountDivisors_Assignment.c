#include<stdio.h>
int main()
{
  int FI, SI, TI, counter = 0;
  scanf("%d %d %d", &FI, &SI, &TI);
  for(int changer = FI; changer <= SI; changer++)
  {
    if(changer % TI == 0){counter++;}
  }
  printf("%d \n", counter);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
