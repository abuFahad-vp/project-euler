
#include <stdio.h>
#include <math.h>

#define limit 1500000

int gcd(long a,long b)
{
  long x,y;
  if(a>b)
  {
    x=a;
    y=b;
  }
  else
  {
    x=b;
    y=a;
  }
  while(x%y != 0)
  {
    long temp = x;
    x = y;
    y = temp%x;
  }
  return y;
}

int main()
{
  int triangles[limit+1] = {0};

  int result = 0;
  int mlimit = sqrt(limit/2);

  for(long m=2;m<mlimit;m++)
  {
    for(long n=1;n<m;n++)
    {
      if((n+m)%2==1 && gcd(n,m)==1)
      {
        long a = m*m + n*n;
        long b = m*m - n*n;
        long c = 2*m*n;
        long p = a+b+c;
        while(p<=limit)
        {
          triangles[p]++;
          if (triangles[p] == 1) result++;
          if (triangles[p] == 2) result--;
          p += a+b+c;
        }
      }
    }
  }
  printf("%d\n",result);
  return 0;
}

