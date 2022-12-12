
#include <stdio.h>
#include "euler.h"

#define SIZE 9
#define NUM 50
void read(int grid[NUM][SIZE][SIZE])
{
  FILE* fp = fopen("project96.txt","r");
  char line[11];
  for(int i=0;i<NUM;i++)
  {
    fgets(line,sizeof(line),fp);
    for(int k=0;k<SIZE;k++)
    {
      fgets(line,sizeof(line),fp);
      for(int n=0;n<SIZE;n++)
      {
        grid[i][k][n] = line[n] - '0';
      }
      
    }
  }
}

int main()
{
  int grid[NUM][SIZE][SIZE];
  read(grid);
  int ans = 0;
  for(int i=0;i<NUM;i++)
  {
    solveSudoku(grid[i]);
    ans += grid[i][0][0]*100+grid[i][0][1]*10+grid[i][0][2];
  }
  printf("%d\n",ans);
  return 0;
}
