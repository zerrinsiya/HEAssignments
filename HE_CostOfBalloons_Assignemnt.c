#include<stdio.h>
int main()
{
  int testCases, cost1, cost2, HL, C1, C2, sum1, sum2=0;
  scanf("%d", &testCases);
  for(int changer = 1; changer <= testCases; changer++)
  {
    scanf("%d %d", &cost1, &cost2);
    scanf("%d", &HL);
    for(int changer = 1; changer <= HL; changer++)
    {
      scanf("%d %d", &C1, &C2);
      sum1 = (sum1 + ((C1 * cost1) + (C2 * cost2)));
      sum2 = (sum2 + ((C1 * cost2) + (C2 * cost1)));
    }
    if(sum1 < sum2){printf("%d \n",sum1);}
    else{printf("%d \n",sum2);}
    sum1 = 0;
    sum2 = 0;
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved. \n");
}
