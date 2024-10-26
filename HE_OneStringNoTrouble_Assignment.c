#include<stdio.h>
#include<string.h>
#include<time.h>
int main()
{


  char s[1000000];
/*
  FILE *fp;
  fp = fopen("c:\\temp\\a.txt", "r");
  if (fp == NULL)
  {
        printf("Error reading file\n" );
        return 0;
  }
  fgets(s,1000000, fp);
  fclose(fp);*/

  gets(s);
  clock_t tic = clock();
  unsigned int x = 0, k = 1;
  for(int i = strlen(s) - 1; i--;)
  {
    if(s[i] != s[i + 1]){k++;}
    else{x = (x > k? x : k); k = 1;}
  }
  x = (x > k? x : k);
  printf("%d \n",x);

  clock_t toc = clock();
  printf("%f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
