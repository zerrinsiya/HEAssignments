#include<stdio.h>
int main()
{
  int lenght, pics, width, height;
  scanf("%d", &lenght);
  scanf("%d", &pics);
  while(pics--)
  {
    scanf("%d%d", &width, &height);
    if((width < lenght) || (height < lenght)){printf("UPLOAD ANOTHER\n");}
    else if((width == lenght) && (height == lenght) || (width == height)){printf("ACCEPTED \n");}
    else{printf("CROP IT \n");}
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved. \n");
}
