#include<stdio.h>
#include<string.h>
int main()
{
  int limit;
  scanf("%d", &limit);
  char input[limit];
  scanf("%s", &input);
  for(int changer = 0; changer < strlen(input); changer++)
  {
    if(input[changer] == '.')
  	{
    	input[changer] = 'B';
   	}
	}
  if(strstr(input, "HH")){printf("NO \n");}
  else{printf("YES \n%s \n",input);}
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
