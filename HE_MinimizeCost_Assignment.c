#include<stdio.h>
int min(int HI, int hi){return HI > hi? hi : HI;}
int main()
{
  /*
  FILE READING INPUT
  int temp = 0;
  int flag = 0;
  long k = 0;
  long size = 0;
  long long int sum = 0;
  int j = 0;

  size = 100000; k = 72683;
  long long int array[size];

  FILE *fp;
  fp = fopen("c:\\temp\\InputForMCAssignment.txt", "r");
  if (fp == NULL)
  {
        printf("Error reading file\n" );
        return 0;
  }
  for (int m = 0; m < size; m++)
  {
    fscanf(fp, "%lld", &array[m]);
  }
  fclose(fp);
  */
  long k = 0;
  long size = 0;
  long long int sum = 0;
  int j = 0;
  scanf("%ld %ld", &size, &k);
  long array[size];
  for(int changer = 0; changer < size; changer++)
  {
    scanf("%ld", &array[changer]);
  }
  if(k == size / 2)
  {
    for (int changer = 0, temp = 0; changer < k; changer++)
    {
      temp++;
      if(changer == k){sum = 0;}
      if(array[changer] == temp){continue;}
      break;
    }
  }
  else
  {
    for(int i = 0; i < size; i++)
    {
      if(array[i] <= 0){continue;}
      while(j <= (i + k) && j < size && array[i] != 0)
      {
        if(array[j] > 0){j++; continue;}
        long long int x = min(array[i],abs(array[j]));
        array[i] -= x;
        array[j] += x;
        if(array[j]>=0)
        j++;
      }
    }
    for(int changer = 0; changer < size; changer++)
    {
      sum = sum + abs(array[changer]);
    }
  }
  printf("%lld\n", sum);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
