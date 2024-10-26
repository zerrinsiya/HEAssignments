#include<stdio.h>
#include<string.h>
char *inputString(FILE* fp, size_t size)
{
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

int main()
{
  char c;
  int endSize = 0;
  int size = 0;
  char* input;
  int L, U, R, D = 0;
  scanf("%d\n",&size);

  for (int changer = 0; changer < size; changer++)
  {
    input = inputString(stdin, 10);
    L = 0;
    U = 0;
    R = 0;
    D = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        c = input[i];
       if(c == 'L'){L++;}
       if(c == 'U'){U++;}
       if(c == 'R'){R++;}
       if(c == 'D'){D++;}
    }
    endSize = ((abs(L - R) / 2) + (abs(L - R) % 2)) + ((abs(U - D) / 2) + (abs(U - D) % 2));
    printf("%d \n",endSize);
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
