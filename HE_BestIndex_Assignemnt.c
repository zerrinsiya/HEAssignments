#include<stdio.h>
int main()
{
  int size = 0;
  scanf("%d", &size);
  int array[size];
  int NI, tc = 0;
  long bigSum = 0, sum = 0;
  long totalSum = 0;
  long trailingSum = 0;
  long upperSum = 0;
  int isFirst = 1;
  for (int changer = 0; changer < size; changer++)
  {
    scanf("%d", &array[changer]);
    totalSum += array[changer];
    //array[changer] += array[changer-1];
  }

  for (int changer = 0; changer < size; changer++)
  {
    NI = 0;
    tc = 0;
    sum = 0;
    upperSum = 0;
    while (NI + changer < size)
    {
      tc++;
      if(NI + changer + tc > size){break;}
    /*  for (int k = (changer + NI)  ; k < (changer + NI + tc) ; k++) {
        sum += array[k];
      }*/
      NI += tc;
    }
    for(int j = changer + NI ; j < size; j++)
    {
      upperSum += array[j];
    }
    if(changer > 0)
    {
      trailingSum += array[changer - 1];
    }
    sum = totalSum - upperSum - trailingSum;
    //sum = array[changer + NI - 1]  - array[changer];
    //printf("total sum = %ld current sum = %ld upper sum = %ld  lowersum = %ld\n",  totalSum, sum, upperSum, trailingSum);
    if (isFirst == 1)
    {
      bigSum = sum;
      isFirst = 0;
    }
    else
    {
      if(sum > bigSum){bigSum = sum;}
    }
  }
  printf("%ld\n",bigSum);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
