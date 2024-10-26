#include<stdio.h>
#include<string.h>
int main()
{
  char s[100];
  unsigned int n = 0, alpha = 0, count = 0, flag = 0, x = 0;

  scanf("%d\n", &n);

  /*clock_t tic = clock();
  n = 41249;
  FILE *fp;
  fp = fopen("c:\\temp\\a.txt", "r");
  if (fp == NULL)
  {
        printf("Error reading file\n" );
        return 0;
  }*/
  for (int changer = n; changer--;)
  {
    gets(s);


    //fgets(s,100, fp);


    count = 0, flag = 0, alpha = 0, x = 0;
    for (int changer = strlen(s); changer--;)
    {
      if((changer >= 1 && (s[changer] == 48 && s[changer - 1] == 32)) || (changer == 0 && s[changer] == 48)){flag = 1; break;}
    }
    if(flag == 0)
    {
      for (int y = strlen(s); y--;)
      {
        if(alpha == 0 && s[y] >= 65 && s[y] <= 122 && x == 0){alpha = 1;}
        if(alpha == 1 && s[y] == 32){x = 1;}
        if(x == 1 && s[y] >= 65 && s[y] <= 122){x = 2; break;}
        if(s[y] == 32){count++;}
      }
    }
    else{printf("N\n"); continue;}
    if(x == 2){printf("N\n"); continue;}
    else if(alpha == 1 && count == 2){printf("V\n"); continue;}
    else if(alpha == 1 && count == 1){printf("M\n"); continue;}
    else if(alpha == 0){printf("N\n"); continue;}
  }
  //fclose(fp);
}
