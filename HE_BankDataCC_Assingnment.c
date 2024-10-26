#include<stdio.h>
#include<stdlib.h>
struct Node
{
  long long int value;
  struct Node* leftNode;
  struct Node* rightNode;
  int count;
};
struct Node* newNode(long long int data)
{
  struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
  Node->value = data;
  Node->count = 1;
  Node->leftNode = NULL;
  Node->rightNode = NULL;
  return (Node);
}
int FindNode(struct Node* rootNode, int value)
{
  if(rootNode->value == value){return rootNode->count;}
  if(rootNode->value < value){return FindNode(rootNode->rightNode, value);}
  if(rootNode->value > value){return FindNode(rootNode->leftNode, value);}
}
int AddNode(struct Node* rootNode, int value)
{
  if(rootNode->value == value)
  {
    rootNode->count++;
    return 0;
  }

  if(rootNode->value < value)
  {
    if(rootNode->rightNode == NULL)
    {
      struct Node* rightNode =  newNode(value);
      rootNode->rightNode = rightNode;
      return 0;
    }
    return AddNode(rootNode->rightNode, value);
  }

  if(rootNode->value > value)
  {
    if(rootNode->leftNode == NULL)
    {
      struct Node* leftNode =  newNode(value);
      rootNode->leftNode = leftNode;
      return 0;
    }
    return AddNode(rootNode->leftNode, value);
  }
}
int main()
{
  int changer = 0;
  long long int x = 0, y = 0;
  int* a1;
  int* a2;
  a1 = (int*)malloc(sizeof(int)*1);
  a2 = (int*)malloc(sizeof(int)*1);

  struct Node* rootNode =  newNode(0);

  for (changer = 0; changer > -1; changer++)
  {
    scanf("%lld %lld", &x, &y);
    if(x == -1 || y == -1){break;}
    AddNode(rootNode, x);
    AddNode(rootNode, y);

    a1[changer] = x;
    a2[changer] = y;

    a1 = realloc(a1,sizeof(int)*(changer + 2));
    a2 = realloc(a2,sizeof(int)*(changer + 2));

  }
  for (int i = 0; i < changer; i++)
  {
    int c1 = FindNode(rootNode, a1[i]);
    int c2 = FindNode(rootNode, a2[i]);
    if((c1 > 1 && c2 > 1) || (c1 == 1 && c2 == 1)){printf("-1 -1\n"); continue;}
    if(c1 > 1){printf("0 1\n"); continue;}
    if(c2 > 1){printf("1 0\n"); continue;}
  }

  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
