
#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool ispossible(int grid[SIZE][SIZE],int number,int row,int column)
{
  //check on the rows
  for(int i=0;i<SIZE;i++)
  {
    if(grid[row][i]==number)
    {
      return false;
    }
  }
  //check on the column
  for(int i=0;i<SIZE;i++)
  {
    if(grid[i][column]==number)
    {
      return false;
    }
  }
  //check on the box
  int localRow = row - row%3;
  int localColumn = column - column%3;
  for(int i=localRow;i<localRow+3;i++)
  {
    for(int k=localColumn;k<localColumn+3;k++)
    {
      if(grid[i][k]==number)
      {
        return false;
      }
    }
  }
  return true;
}

bool solveSudoku(int grid[SIZE][SIZE])
{
  for(int row=0;row<SIZE;row++)
  {
    for(int column=0;column<SIZE;column++)
    {
      if(grid[row][column]==0)
      {
        for(int numberTotry=1;numberTotry<=SIZE;numberTotry++)
        {
          if(ispossible(grid,numberTotry,row,column))
          {
            grid[row][column] = numberTotry;

            if(solveSudoku(grid))
            {
              return true;
            }
            else
            {
              grid[row][column] = 0; 
            }
          }
        }
        return false;
      }
    }
  }
  return true;
}

//int main()
//{
//  int grid[SIZE][SIZE] = {{0,0,3,0,2,0,6,0,0},
//              {9,0,0,3,0,5,0,0,1},
//              {0,0,1,8,0,6,4,0,0},
//              {0,0,8,1,0,2,9,0,0},
//              {7,0,0,0,0,0,0,0,8},
//              {0,0,6,7,0,8,2,0,0},
//              {0,0,2,6,0,9,5,0,0},
//              {8,0,0,2,0,3,0,0,9},
//              {0,0,5,0,1,0,3,0,0}};
//  solve(grid);
//  for(int i=0;i<SIZE;i++)
//  {
//    for(int k=0;k<SIZE;k++)
//    {
//      printf("%d ",grid[i][k]);
//    }
//    printf("\n");
//  }
//}





