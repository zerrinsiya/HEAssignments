#include<stdio.h>
#include"Helper_Functions_1D_Array.c"
void HighSearch(int n, int a[n])
{
  int h = 0, in = 0;
  for (n; n--;)
  {
    if(h <= a[n]){h = a[n]; in = n;}
    //printf("n = %d, a[n] = %d, h = %d, in = %d \n", n, a[n], h, in);
  }
  //printf("h = %d , in = %d \n", h, in);
  a[in] = 0;
  printf("%d \n", in + 1);
  //printf("\n");
}
int main()
{
  int n = 0, k = 0;
  scanf("%d %d", &n, &k);
  int a[n];
  for (int i = n; i--;)
  {
    scanf("%d", &a[i]);
  }
  //Printer(a, n);
  for (int i = k; i--;)
  {
    HighSearch(n, a);
  }
}
