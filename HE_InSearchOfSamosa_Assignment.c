#include<stdio.h>
#include<stdlib.h>

int gcount = 0;

struct Node
{
  long long int value;
  struct Node* leftNode;
  struct Node* rightNode;
  int count;
};

struct Node* newNode(int value)
{
  struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
  Node->value = value;
  Node->leftNode = NULL;
  Node->rightNode = NULL;
  Node->count = 1;
  return (Node);
}

int AddNode(struct Node* rootNode, int value)
{
  if(rootNode->value <= value)
  {
    if(rootNode->rightNode == NULL)
    {
      struct Node* rightNode =  newNode(value);
      rootNode->rightNode = rightNode;
      rootNode->rightNode->count = 1;
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
      rootNode->leftNode->count = 1;
      return 0;
    }
    return AddNode(rootNode->leftNode, value);
  }
}

int SearchForA(struct Node* rootNode, int value, int f)
{
  if(f == 0)
  {
    if(rootNode == NULL){return 0;}
    if(rootNode->value == value){if(f == 0){rootNode->count++;} return rootNode->value;}
    else if(rootNode->value < value){return SearchForA(rootNode->rightNode, value, f);}
    else if(rootNode->value > value){return SearchForA(rootNode->leftNode, value, f);}
  }

  if(f == 1)
  {
    if(rootNode == NULL){return 0;}
    if(rootNode->value == value){return rootNode->value;}
    else{return -1;}
  }
}

int SearchSpend(struct Node* rootNode, int k, int l, int h)
{
  int tv = 0;
  for (l; l <= h; l++)
  {
    printf("%d \n", rootNode->leftNode->leftNode->value);
    if(SearchForA(rootNode, l, 1) == l)
    {
      tv = l;
      printf(" count = %d, value = %d, l = %d \n", rootNode->count, rootNode->value, l);
      if(k - (tv * rootNode->count) >= 0){k -= tv; gcount + rootNode->count; rootNode->count = 0;}
      else{return 0;}
      continue;
    }
    else{continue;}
  }
}

int main()
{
  int t = 0, k = 0, a = 0, lowest = 0, highest = 0;
  scanf("%d %d", &t, &k);
  struct Node* rootNode;
  for (int i = t; i--;)
  {
    scanf("%d", &a);
    if(i == t - 1){rootNode = newNode(a); lowest = a; highest = a;}
    else
    {
      if(SearchForA(rootNode, a, 0) != 0){continue;}
      else{AddNode(rootNode, a);}
      if(lowest >= a){lowest = a;}
      if(highest <= a){highest = a;}
    }
  }
  SearchSpend(rootNode, k, lowest, highest);
  //printf("%d \n", gcount);
}
