
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ll long long

long long Primes(long long primes[],int lower,int upper)
{
  bool boolPrime[upper+1];
  memset(boolPrime,true,sizeof(boolPrime));

  for(int p=2;p<=upper;p++)
  {
    if(boolPrime[p])
    {
      for(int i=p*p;i<=upper;i += p)
      {
        boolPrime[i] = false;
      }
    }
  }

  int i=0;
  for(;lower<=upper;lower++)
  {
    if(boolPrime[lower]) 
    {
      primes[i]=lower;
      i++;
    }
  }
  return i;
}

