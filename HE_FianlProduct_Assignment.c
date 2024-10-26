#include<stdio.h>
#include<math.h>
int main()
{
  int size = 0;
  scanf("%d \n", &size);
  int array[size];
  for (int changer = 0; changer < size; changer++)
  {
    scanf("%d", &array[changer]);
  }
  unsigned long long int product = 1;
  for (int changer = 0; changer < size; changer++)
  {
    product = (product * array[changer]) % 1000000007;
  }
  printf("%llu \n",product);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
