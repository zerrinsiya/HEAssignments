#include<stdio.h>
int main()
{
  long size, minValue = 0;
  long step = 0;
  int flag = 0;
  scanf("%ld", &size);
  long a[size], b[size];
  for (int changer = 0; changer < size; changer++)
  {
    scanf("%ld", &a[changer]);
    if(flag == 0)
    {
      flag = 1;
      minValue = a[changer];
    }
    else if(a[changer] < minValue)
    {
      minValue = a[changer];
    }
  }
  for (int changer = 0; changer < size; changer++)
  {
    scanf("%ld", &b[changer]);
  }
  for (int changer = 0; changer < size; changer++)
  {
    if(a[changer] != minValue)
    {
      if((a[changer] - minValue) % b[changer] == 0){step += (a[changer] - minValue) / b[changer];}
      else
       {
         step = -1;
         if(minValue == 0) { break; }
         else { minValue--; changer = -1; step = 0; continue;}
       }
    }
  }
  printf("%ld \n",step);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
