
#include <stdio.h>
#include "euler.h"
#include <math.h>

void copy(ll tmp[],ll original[], int len)
{
  for(int i=0;i<len;i++)
  {
    tmp[i] = original[i];
  }
}

int main()
{
  ll primes[950];


  ll len = Primes(primes,2,7072);
  ll powers[len][len];

  ll tmp[len];
  copy(tmp,primes,len);

  for(int j=0;j<3;j++)
  {
    for(int i=0;i<len;i++)
    {
      tmp[i] *= primes[i];
    }
    copy(powers[j],tmp,len);
  }

  int count = 0;
  for(int i=0;i<len;i++)
  {
    for(int j=0;j<len;j++)
    {
      for(int k=0;k<len;k++)
      {
        ll sum = pow(primes[i],2)  + pow(primes[j],3) + pow(primes[k],4);
        if(sum > 50000000) break;
        printf("%Ld\n",sum);
        count++;
      }

    }
  }

  printf("Count = %d\n",count);
  return 0;
}
