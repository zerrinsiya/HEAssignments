#include<stdio.h>
#include<string.h>
int main()
{
  char input[100];
  scanf("%s", &input);
  for (int changer = 0; changer < strlen(input); changer++)
  {
    if(input[changer] >= 65 && input[changer] <= 90){input[changer] = tolower(input[changer]); continue;}
    if(input[changer] >= 90 && input[changer] <= 122){input[changer] = toupper(input[changer]); continue;}
  }
  printf("%s\n",input);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
