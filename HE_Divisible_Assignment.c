#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
  int size;
  scanf("%d",&size);
  int input;
  int temp;
  int counterChange = -1;

  for(int changer = 0; changer < size;  changer++)
  {
    scanf("%d", &input);
    counterChange = counterChange * -1;
    if(changer < (size / 2))
    {
      while(input >= 10)
      {
        input = input / 10;
      }
      temp += input * counterChange;
    }
    else
    {
      temp += (input % 10) * counterChange;
    }
  }
  /*memcpy(temp, output, size);
  temp[size] = '\0';
  FinalOutput = atoi(temp);*/
  if(temp % 11 == 0)
  {
    printf("OUI");
  }
  else
  {
    printf("NON");
  }
  printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
