#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node
{
  long long int value;
  struct Node* leftNode;
  struct Node* rightNode;
  int ID;
  int ET;
  int WT;
  int TR;
  int staff;
  int TOSA;
};
struct Node* newNode(int clientID, int entryTime, int waitingTime, int timeRequired)
{
  struct Node* Node = (struct Node*)malloc(sizeof(struct Node));
  Node->value = entryTime;
  Node->leftNode = NULL;
  Node->rightNode = NULL;
  Node->ID = clientID;
  Node->WT = waitingTime;
  Node->TR = timeRequired;
  Node->ET = entryTime;
  Node->staff = 0;
  Node->TOSA = 0;
  return (Node);
}
int AddNode(struct Node* rootNode, int clientID, int entryTime, int waitingTime, int timeRequired)
{

  if(rootNode->value <= entryTime)
  {
    if(rootNode->rightNode == NULL)
    {
      struct Node* rightNode =  newNode(clientID, entryTime, waitingTime, timeRequired);
      rootNode->rightNode = rightNode;
      return 0;
    }
    return AddNode(rootNode->rightNode, clientID, entryTime, waitingTime, timeRequired);
  }

  if(rootNode->value > entryTime)
  {
    if(rootNode->leftNode == NULL)
    {
      struct Node* leftNode =  newNode(clientID, entryTime, waitingTime, timeRequired);
      rootNode->leftNode = leftNode;
      return 0;
    }
    return AddNode(rootNode->leftNode,  clientID, entryTime, waitingTime, timeRequired);
  }
}
int StaffAssignment(struct Node* rootNode, int value, int* staff, int k)
{

  int flag = 0;
  int min = 0;
  int changer = 0;
  if(rootNode->value == value && rootNode->staff == 0)
  {
    for (int i = 0; i < k; i++)
    {
      if(rootNode->ET >= staff[i])
      {
        staff[i] = rootNode->ET + rootNode->TR;
        rootNode->TOSA = (staff[i] - rootNode->TR);
        rootNode->staff = i + 1;
        flag = 1;
        break;
      }
    }
    if(flag == 0)
    {
      for (changer = 0; changer < k; changer++)
      {
        if(rootNode->ET + rootNode->WT > staff[changer] && (rootNode->ET + rootNode->WT) != 1050)
        {
          if(min = 0){min = changer;}
          else{if(staff[min] > staff[changer]){min = changer;}}
        }
      }
      if(min > 0)
      {
        staff[min] += rootNode->WT;
        rootNode->TOSA = (staff[min] - rootNode->TR);
        rootNode->staff = min + 1;
        flag = 1;
      }
    }
    if(flag = 0){rootNode->staff = -1;}
    return 0;
  }
  if(rootNode->value == value && rootNode->staff != 0){return StaffAssignment(rootNode->rightNode, value, staff, k);}
  if(rootNode->value < value){return StaffAssignment(rootNode->rightNode, value, staff, k);}
  if(rootNode->value > value){return StaffAssignment(rootNode->leftNode, value, staff, k);}
}
int searchID(struct Node* rootNode, long long int id, long long int time, int flag)
{
  if(rootNode->ET == time)
  {
    if(rootNode->ID == id)
    {
      if(flag == 0){return rootNode->staff;}
      if(flag == 1){return rootNode->TOSA;}
    }
    else
    {
      return searchID(rootNode->rightNode, id, time, flag);
    }
  }
  if(rootNode->ET < time){return searchID(rootNode->rightNode, id, time, flag);}
  if(rootNode->ET > time){return searchID(rootNode->leftNode, id, time, flag);}
}
int main()
{
  long long int n = 0, k = 0, ID = 0, ET = 0, WT = 0, TR = 0, staffID = 0, TOSA = 0;
  float HF;
  int flag = 0;
  scanf("%d %d", &n, &k);
  int* staff;
  staff = (int*) calloc(k, sizeof(int));
  int id_arr[n],  et_arr[n];
  int time[960] = {0};
  struct Node* rootNode;
  for (int changer = 0; changer < n; changer++)
  {
    scanf("%d %d %d %f %d", &ID, &ET, &WT, &HF, &TR);
    id_arr[changer] = ID, et_arr[changer] = ET;
    time[ET]++;
    if(changer == 0){rootNode =  newNode(ID, ET, WT, TR); continue;}
    else{AddNode(rootNode, ID, ET, WT, TR);}
  }
  for (int i = 540; i < 960; i++)
  {
    if(time[i] >= 1)
    {
      for (int changer = 0; changer < time[i]; changer++)
      {
        StaffAssignment(rootNode, i, staff, k);
      }
    }
  }
  for (int changer = 0; changer < n; changer++)
  {

    staffID = searchID(rootNode, id_arr[changer], et_arr[changer], 0);
    if(staffID == -1){printf("-1 -1\n"); continue;}
    else
    {
      TOSA = searchID(rootNode, id_arr[changer], et_arr[changer], 1);
      printf("%d %d\n", TOSA, staffID);
    }
  }
  printf("Copyright (c) 2021 Copyright Holder All Rights Reserved.");
}
