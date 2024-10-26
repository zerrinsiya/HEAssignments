#include<stdio.h>
#include<string.h>
int main()
{
  char input[10];
  scanf("%s", &input);
  for (int changer = 0; changer < strlen(input); changer++)
  {
    if(strlen(input) == 9)
    {
      if(input[2] != 'A' && input[2] != 'E' && input[2] != 'I' && input[2] != 'O' && input[2] != 'U' && input[2] != 'Y')
      {
        if((input[0] + input[1]) % 2 == 0 && (input[3] + input[4]) % 2 == 0 && (input[4] + input[5]) % 2 == 0 && (input[7] + input[8]) % 2 == 0){printf("valid");break;}
        else{printf("invalid");break;}
      }
      else{printf("invalid");break;}
    }
    else{printf("invalid");break;}
  }
  printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
