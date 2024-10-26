#include<stdio.h>
int main()
{
  int input;
  for (int changer = 0; changer > -1; changer++)
  {
    scanf("%d", &input);
    if(input != 42){printf("%d \n",input);}
    else{break;}
    input = 0;
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
