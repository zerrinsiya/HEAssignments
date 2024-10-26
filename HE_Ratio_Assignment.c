#include<stdio.h>
#include"Helper_Functions_1D_Array.c"
int Ratio(int n, int a[n])
{
  int count = 0, rOne = 0, rTwo = 0;
  for(int i = n; i--;)
  {
    if(i == n - 1){rOne = a[i]; rTwo = a[i - 1]; continue;}
    i--;
    if(rOne == a[i] && a[i - 1]){count++;}
    else{printf("1\n"); return 0;}
  }
  printf("%d \n", count);
}

int AllNormal(int n, int a[n])
{
  int ans = a[n - 1];
  for(int i = n - 1; i--;)
  {
    ans = a[i] - ans;
  }
  if(ans == 0){printf("%d \n",n - 1);}
  else{printf("1\n");}
}

int AllSame(int n, int k[n])
{
  int sum = 0;
  for (int i = n; i--;)
  {
    sum += k[i];
  }
  printf("%d \n", sum);
}

int main()
{
  int y = 0, t = 0, n = 0;
  scanf("%d", &t);
  for (int i = t; i--;)
  {
    scanf("%d", &n);
    int k[n];
    char c[n];
    for (int changer = n; changer--;)
    {
      scanf("%d %c", &k[changer], &c[changer]);
    }
    for (int z = 0, changer = n; changer--;)
    {
      if(c[changer] == 'A' && changer == n){z = 1;}
      else{z = 0;}
      if(c[changer] == 'A' && z == 1){y = 0; z = 1;}
      else if(c[changer] == 'B' && z == 0){y = 0; z = 0;}
      else{y = 1; break;}
    }
    if(y == 0){AllSame(n, k); continue;}
    y = 0;
    int a[n];
    for (int changer = n; changer--;)
    {
      if(changer > 0 && c[changer] == c[changer - 1]){a[y] = k[changer] + k[changer - 1]; changer--; y++;}
      else{a[y] = k[changer]; y++;}
    }
    if(y == 2 && a[0] > a[1]){printf("1\n"); continue;}
    else if(a[n] > a[n - 1]){AllNormal(y, a); continue;}
    else if(a[n] <= a[n - 1]){printf("check enter\n"); Ratio(y, a); continue;}
  }
}
