#include<stdio.h>
int main()
{
  int x = 0, p = 0, s = 0, t = 0, h = 0, out = 0;
  scanf("%d %d %d %d %d", &p, &s, &t, &h, &x);
  for(x = x; x--;)
  {
    if(s <= t){out += h;}
    else{out = out + p;}
    s--;
  }
  printf("%d\n", out);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");  
}
