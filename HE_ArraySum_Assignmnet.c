#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
  int inputSize;
	unsigned long long int sum = 0;
  unsigned long long int selectedInput = 0;
  scanf("%d ", &inputSize);

  for (int i = 0; i < inputSize; i++) {
    scanf("%llu", &selectedInput);
    sum += selectedInput;
  }

  printf("%llu \n",sum);
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
