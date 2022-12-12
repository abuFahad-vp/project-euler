
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define V 51*51
#define C 51

typedef struct {
  int x;
  int y;
} ord;

//(0,0) is common to all triangle
//not square root (for presicion)
double distance(ord A, ord B)
{
  double x = pow(A.x-B.x,2);
  double y = pow(A.y-B.y,2);
  return x+y;
}

bool isRight(ord A,ord B)
{
  ord origin;
  origin.x = 0;
  origin.y = 0;
  double S1 = distance(A,B);
  double S2 = distance(origin,A);
  double S3 = distance(origin,B);
  if(S1 > S2 && S1 > S3)
  {
    if(S1 == (S2+S3)) return true;
    return false;
  }
  if(S2 > S1 && S2 > S3)
  {
    if(S2 == (S1+S3)) return true;
    return false;
  }
  if(S3 > S1 && S3 > S2)
  {
    if(S3 == (S1+S2)) return true;
    return false;
  }
  return false;
}

int main()
{
  ord points[V];
  int index = 0;
  for(int x=0;x<C;x++)
  {
    for(int y=0;y<C;y++)
    {
      points[index].x = x;
      points[index].y = y;
      index++;
    }
  }
  int count = 0;
  for(int i=1;i<index;i++)
  {
    for(int k=i+1;k<index;k++)
    {
      if(isRight(points[i],points[k]))
      {
        count++;
      }
    }
  }
  printf("%d\n",count);
  return 0;
}

