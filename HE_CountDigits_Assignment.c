#include<stdio.h>
#include<string.h>
int main()
{
  char s[100];
  int result[10] = {0,0,0,0,0,0,0,0,0,0};
  scanf("%s",s);
  for(int changer = 0; changer < strlen(s); changer++)
  {
    result[s[changer] - 48]++;
  }
  for(int changer = 0; changer < 10; changer++)
  {
    printf("%d %d \n", changer, result[changer]);
  }
  printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
