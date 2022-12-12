
#include <stdio.h>

#define V 6400

void Matrix(int arr[V][V])
{
  FILE* f = fopen("dump.txt","r");
  char dlt[200000];
  for(int k=0;k<V;k++)
  {
    for(int i=0;i<V;i++)
    {
      fscanf(f,"%d",&arr[k][i]);
    }
    fgets(dlt,sizeof(dlt),f);
  }
}
