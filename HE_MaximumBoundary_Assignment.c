
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num;
	int row, column;
	scanf("%d", &num);   // Reading input from STDIN
	for(int i = 0 ; i < num ; i++)
	{
		scanf("%d", &row);
		scanf("%d", &column);
		char inputstring[column];
		int array[row][column];
		for(int j = 0 ; j < row; j++)
		{
			scanf("%s", inputstring);
			for( int col = 0; col < column; col++)
			{
				if(inputstring[col] == '.') {array[j][col] = 0;}
				if(inputstring[col] == '#') {array[j][col] = 1;}
			}
		}
		printf("%d\n",CheckBoundary(row, column, array));
	}
	printf("\nCopyright (c) 2021 Copyright Holder All Rights Reserved.");
}
int CheckBoundary(int SizeRow, int SizeColumn, int array[SizeRow][SizeColumn])
{
	int bc = 0;
  int counter = 0;
  int HigestBoundary = 0;
	int BoundaryCheckLeft = 0;
	int BoundaryCheckRight = 0;
	int BoundaryCheckUp = 0;
	int BoundaryCheckDown = 0;
  for (int row = 0; row < SizeRow; row++)
  {

    for (int column = 0; column < SizeColumn; column++)
    {
      if(array[row][column] == 1)
      {
				if(BoundaryCheckUp == 1 && BoundaryCheckDown == 1){if(HigestBoundary < counter){HigestBoundary = counter; counter = 0; continue;}}
				if(BoundaryCheckUp == 1)
				{

					if(column > 0 && array[row - 1][column] == 0)
					{
						if(array[row + 1][column] == 0)
						{
							bc++;
						}
						else
						{
							if(bc > HigestBoundary){HigestBoundary = bc;}
			        bc = 0;
						}
						counter++;
						continue;
					}
					else
					{
						if(row < SizeRow && array[row + 1][column] != 0 && row < SizeRow && array[row - 1][column] != 0)
						{
							if(counter > HigestBoundary){HigestBoundary = counter;}
							counter = 0;
							counter = bc ;
							bc = 0;
							if(BoundaryCheckDown == 0 && (row < SizeRow && array[row + 1][column] == 0)){BoundaryCheckDown = 1;BoundaryCheckUp = 0; continue;}
						}
						else
						{
							bc++;
						}
						if(counter > HigestBoundary){HigestBoundary = counter;}
						counter = 0;
						counter = bc ;
						bc = 0;
						if(BoundaryCheckDown == 0 && (row < SizeRow && array[row + 1][column] == 0)){BoundaryCheckDown = 1;BoundaryCheckUp = 0; continue;}
					}
				}
				if(BoundaryCheckDown == 1)
				{

					if(column < SizeColumn && array[row + 1][column] == 0)
					{
						if(array[row - 1][column] == 0)
						{
							bc++;
						}
						else
						{
							if(bc > HigestBoundary){HigestBoundary = bc;}
			        bc = 0;
						}
						counter++;
						continue;
					}
					else
					{
						if(row < SizeRow && array[row + 1][column] != 0 && row < SizeRow && array[row - 1][column] != 0)
						{
							if(counter > HigestBoundary){HigestBoundary = counter;}
							counter = 0;
							counter = bc ;
							bc = 0;
							if(BoundaryCheckUp == 0 && (row < SizeRow && array[row - 1][column] == 0)){BoundaryCheckUp = 1;BoundaryCheckDown = 0; continue;}
						}
						else
						{
							bc++;
						}
						if(counter > HigestBoundary){HigestBoundary = counter;}
						counter = 0;
						counter = bc ;
						bc = 0;
						if(BoundaryCheckUp == 0 && (row < SizeRow && array[row - 1][column] == 0)){BoundaryCheckUp = 1;BoundaryCheckDown = 0; continue;}
					}
				}
        if(row == 0 || row == SizeRow - 1){counter++; continue;}
        if(BoundaryCheckUp == 0 && (row > 0 && array[row - 1][column] == 0)){BoundaryCheckUp = 1; counter++; bc++; continue;}
        if(BoundaryCheckDown == 0 && (row < SizeRow && array[row + 1][column] == 0)){BoundaryCheckDown = 1; counter++; bc++; continue;}
        if(counter > HigestBoundary){HigestBoundary = counter;}
        counter = 0;
      }
      else
      {
        if(counter > HigestBoundary){HigestBoundary = counter;}
        counter = 0;
      }
    }
    if(counter > HigestBoundary){HigestBoundary = counter;}
    counter = 0;
		BoundaryCheckUp = 0;
		BoundaryCheckDown = 0;
		bc = 0;
  }
  //Column Boundary Finder
  counter = 0;
	bc = 0;
  for (int column = 0; column < SizeColumn; column++)
  {
    for (int row = 0; row < SizeRow; row++)
    {
      if(array[row][column] == 1)
      {
				if(BoundaryCheckLeft == 1 && BoundaryCheckRight == 1){if(HigestBoundary < counter){HigestBoundary = counter; counter = 0; continue;}}
				if(BoundaryCheckLeft == 1)
				{
					if(column > 0 && array[row][column - 1] == 0)
					{
						if(array[row][column + 1] ==0)
						{
							bc++;
						}
						else
						{
							if(bc > HigestBoundary){HigestBoundary = bc;}
			        bc = 0;
						}
						counter++;
						continue;
					}
					else
					{
						counter++;
						if(bc > HigestBoundary){HigestBoundary = bc - 1;}
						if(counter > HigestBoundary){HigestBoundary = counter;}
						counter = 0;
						counter = bc - 1 ;
						bc = 0;
						if(BoundaryCheckRight == 0 && (column < SizeColumn && array[row][column + 1] == 0)){BoundaryCheckRight == 1;BoundaryCheckLeft == 0; continue;}
					}
				}
				if(BoundaryCheckRight == 1)
				{

					if(column < SizeColumn && array[row][column + 1] == 0)
					{
						if(array[row][column - 1] == 0)
						{
							bc++;
						}
						else
						{
							if(bc > HigestBoundary){HigestBoundary = bc;}
			        bc = 0;
						}
						counter++;
						continue;
					}
					else
					{
						counter++;
						if(bc > HigestBoundary){HigestBoundary = bc - 1;}
						if(counter > HigestBoundary){HigestBoundary = counter;}
						counter = 0;
						counter = bc ;
						bc = 0;
						if(BoundaryCheckLeft == 0 && (column < SizeColumn && array[row][column - 1] == 0)){BoundaryCheckLeft == 1;BoundaryCheckRight == 0;counter++ ;continue;}
					}
				}
        if(column == 0 || column == SizeColumn - 1){counter++; continue;}
        if(BoundaryCheckLeft == 0 && (column > 0 && array[row][column - 1] == 0)){BoundaryCheckLeft = 1; counter++; continue;}
        if(BoundaryCheckRight == 0 && (column < SizeColumn && array[row][column + 1] == 0)){BoundaryCheckRight = 1; counter++; continue;}
        if(HigestBoundary < counter){HigestBoundary = counter; counter = 0;}
      }
      else
      {
        if(HigestBoundary < counter){HigestBoundary = counter;}
        counter = 0;
      }
    }
		if(HigestBoundary < counter){HigestBoundary = counter;}
    counter = 0;
		BoundaryCheckLeft = 0;
		BoundaryCheckRight = 0;
		bc = 0;
  }
  return HigestBoundary;
}
