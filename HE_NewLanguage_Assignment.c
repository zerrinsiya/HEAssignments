#include<stdio.h>
long long ConvertACL(long long n)
{
	long long ret = 0, i = 0;
	int digit[22];
	while(n)
	{
		digit[i] = n % 10;
		if(digit[i] == 9){digit[i]--;}
		n /= 10;
		i++;
	}
	for(i = i; i--;)
  {
    ret = ret * 9 + digit[i];
  }
	return ret;
}
long long ConvertTL(long long n)
{
	long long ret = 0, i = 0;
	int digit[22];
	while(n)
	{
		digit[i] = n % 9;
		if(digit[i] == 8){digit[i]++;}
		n /= 9;
		i++;
	}
	for(i = i; i--;)
	{
		ret = ret * 10 + digit[i];
	}
	return ret;
}
int main()
{
	long long a = 0, b = 0, c = 0, T = 0;
	char op;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%c%lld",&a,&op,&b);
		a = ConvertACL(a);
		b = ConvertACL(b);
		switch(op)
		{
  		case'+':
  			c = a + b;
  			break;

  		case'-':
  			c = a - b;
  			break;

  		case'*':
  			c = a * b;
  			break;

  		case'/':
  			c = a / b;
  			break;
		}
		c = ConvertTL(c);
		printf("%lld\n",c);
	}
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
