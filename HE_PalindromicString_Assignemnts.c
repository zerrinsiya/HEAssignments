#include<stdio.h>
#include<string.h>
int main()
{
  char input[100];
  scanf("%s", &input);
  int length = strlen(input);
  int midInput = length / 2;
  int counter = 0;
  for(int changer2 = 0, changer1 = length-1; changer2 <= midInput - 1; changer2++, changer1--)
  {
    if(input[changer2] == input[changer1])
    {
      counter++;
    }
    else
    {
      break;
    }
  }
  if(counter == midInput)
  {
    printf("YES");
  }
  else
  {
    printf("NO");
    return 0;
  }
  printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
