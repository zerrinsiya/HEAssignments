#include<stdio.h>
#include<math.h>
long long int result = 0;

long long int CarryMisser(long long int n, long long int m)
{
	long long int sum = 0, mult = 1, x = 0;
	while (n || m)
  {
		x = (n % 10) + (m % 10);
		x %= 10;
		sum += (x * mult);
		n /= 10, m /= 10;
		mult *= 10;
	}
	return sum;
}

int main()
{
  long long int t = 0, a = 0, b = 0, AS = 0;
  scanf("%lld", &t);
  for (int i = t; i--;)
  {
    scanf("%lld", &a);
    scanf("%lld", &b);
    AS = a + b;
    result = CarryMisser(a, b);
    if(AS == result){printf("0\n");}
    else{printf("%lld \n", AS - result > 0 ? AS - result : -1 * (AS - result));}
  }
	printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
