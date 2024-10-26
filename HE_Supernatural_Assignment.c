#include<stdio.h>
#include<stdlib.h>
int digit = 0;
int n = 0;
int counter = 0;

int digitCounter(int x, int flag, int i, int a[i])
{
  int count = 0, product = 1;
  if(flag == 0 || flag == 2)
  {
    while(x > 0)
    {
      product *= x % 10;
      count++;
      x /= 10;
    }
    if(flag == 0){return count;}
    else
    {
      if(product == n){counter++;}
    }
  }
  else
  {
    while(x > 0)
    {
      for (int changer = 0; changer > -1; changer++)
      {
        if(changer > i){return 1;}
        if(x % 10 == a[changer]){break;}
      }
      x /= 10;
    }
    return 0;
  }
}

int loopAndCheck(int i, int a[i])
{
  int p = 0, u = n;
  int flag;
  for(int changer = a[i]; changer > 0; changer *= 10)
  {
    if(digitCounter(p + changer, 0, 0, 0) <= digit){p += changer;}
    else{break;}
  }
  while(u < p)
  {
    u++;
    flag =  digitCounter(u, 1, i, a);
    if(flag == 0){digitCounter(u, 2, 0, 0);}
    else{continue;}
  }
}

int main()
{
  int changer = -1, count = 0, innerCounter = 1;
  int* a;
  a = (int*) malloc(10 * sizeof(int));
  scanf("%d", &n);
  int c = n;
  for (int i = 2; i <= 9; i++)
  {

    if(n % i == 0){changer++; a[changer] = i;}
  }
  while (c > 1)
  {
    c /= 2;
    innerCounter *= 10;
  }
  digit = digitCounter(innerCounter, 0, 0, 0);
  loopAndCheck(changer, a);
  if(digitCounter(n, 0, 0, 0) == 1){counter++;}
  printf("%d\n",counter);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
