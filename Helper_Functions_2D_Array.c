#include <stdio.h>
int Printer(int SizeRow, int SizeColumn, int array[SizeRow][SizeColumn])
{
  for (int row = 0; row < SizeRow; row++)
  {
    for (int column = 0; column < SizeColumn; column++)
    {
      printf("%d ",array[row][column]);
    }
    printf("\n");
  }
}
