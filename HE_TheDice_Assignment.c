#include<stdio.h>
#include<string.h>
int main()
{
  char p[1000000];
  unsigned int count = 0;
  gets(p);
  for (int i = (strlen(p)); i--;)
  {
    if(p[i] != '6' && p[i + 1] != '6'){count++; continue;}
    else if(p[i] == '6' && i == 0 && strlen(p) != 1){continue;}
    else if(p[i] == '6' && i == strlen(p) - 1){printf("-1 \n"); return 0;}
    else if(p[i] == '6' && i != strlen(p) - 1 && p[i + 1] != '6'){count++; continue;}
    else if(p[i] == '6' && i != strlen(p) - 1 && p[i + 1] == '6'){continue;}
  }
  printf("%d \n",count);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
