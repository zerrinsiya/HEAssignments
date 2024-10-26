#include<stdio.h>
#include<string.h>
int main()
{
  char input[20];
  scanf("%s", &input);
  int count_O = 0;
  int count_Z = 0;
  for (int changer = 0; changer < strlen(input); changer++)
  {
    if(input[changer] == 'z'){count_Z++;}
    if(input[changer] == 'o'){count_O++;}
  }
  if(2 *count_Z == count_O ){printf("Yes");}
  if(2 *count_Z != count_O ){printf("No");}
  printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
