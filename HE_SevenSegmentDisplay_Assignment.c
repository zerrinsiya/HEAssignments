#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

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
int GeradeZahlenFunktion(int SiebenSegmentNummer)
{
  for (int Wechsler = 0; Wechsler < SiebenSegmentNummer / 2; Wechsler++)
  {
    printf("1");
  }
}
int UngeradeZahlFunktion(int SiebenSegmentNummer)
{
  printf("7"); GeradeZahlenFunktion(((SiebenSegmentNummer / 2) - 1)*2);
}
int main()
{
  char DividendeNinhaber;
  int SiebenSegmentNummer = 0;
  int WieVieleEingänge = 0;
  char* input;
  scanf("%d \n", &WieVieleEingänge);
  for (int Wechsler = 0; Wechsler < WieVieleEingänge; Wechsler++)
  {
    SiebenSegmentNummer = 0;
    input = inputString(stdin, 10);
    for (int changer = 0; changer < strlen(input); changer++)
    {
      DividendeNinhaber = input[changer];
      if(DividendeNinhaber == '0' || DividendeNinhaber == '6' || DividendeNinhaber == '9'){SiebenSegmentNummer += 6;}
      if(DividendeNinhaber == '1'){SiebenSegmentNummer += 2;}
      if(DividendeNinhaber == '2' || DividendeNinhaber == '3' || DividendeNinhaber == '5'){SiebenSegmentNummer += 5;}
      if(DividendeNinhaber == '4'){SiebenSegmentNummer += 4;}
      if(DividendeNinhaber == '7'){SiebenSegmentNummer += 3;}
      if(DividendeNinhaber == '8'){SiebenSegmentNummer += 7;}
    }
    if(SiebenSegmentNummer % 2 != 0){UngeradeZahlFunktion(SiebenSegmentNummer);}
    if(SiebenSegmentNummer % 2 == 0){GeradeZahlenFunktion(SiebenSegmentNummer);}
    printf("\n");
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
