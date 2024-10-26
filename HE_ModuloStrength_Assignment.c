#include<stdio.h>
int main()
{
  long long int n = 0, c = -1, k = 0, sum = 0, i = 0, NA[100000];
  scanf("%lld %lld", &n, &k);
  long long int a[n];
  for(int changer = 0; changer < n; changer++){NA[changer] = 0;}
  for (i = 0; i < n; i++){scanf("%lld", &a[i]); NA[a[i] % k]++;}
  for (i = 0; i < k; i++){sum += NA[i] * (NA[i] - 1);}
  printf("%lld\n",sum);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
