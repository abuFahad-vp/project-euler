
#include <stdio.h>
#include "euler.h"
#include <math.h>
#include <gmp.h>

int pell(mpz_t oX,int D,mpz_t oY)
{
  mpz_t x;
  mpz_t y;
  mpz_init_set(x,oX);
  mpz_init_set(y,oY);

  mpz_mul(x,x,x);
  mpz_mul(y,y,y);

  mpz_mul_ui(y,y,D);

  mpz_sub(x,x,y);

  return mpz_cmp_ui(x,1);

}

int convergentFraction(contFrac fraction,mpz_t x)
{
  mpz_t N1;
  mpz_t D1;
  mpz_t N2;
  mpz_t D2;
  mpz_t N;
  mpz_t D;
  mpz_t tmp;

  mpz_init_set_ui(N2,fraction.period[1]);
  mpz_init_set_ui(D2,1);
  mpz_init_set_ui(N1,fraction.period[2]*fraction.period[1] + 1);
  mpz_init_set_ui(D1,fraction.period[2]);
  mpz_init(tmp);
  mpz_init(N);
  mpz_init(D);

  if(pell(N1,fraction.period[0],D1) == 0)
  {
    mpz_set(x,N1);
    return 0;
  }
  int i = 3;
  while(1)
  {
    if(i==fraction.length) i = 2;
    mpz_mul_ui(tmp,N1,fraction.period[i]);
    mpz_add(N,N2,tmp);
    mpz_mul_ui(tmp,D1,fraction.period[i]);
    mpz_add(D,D2,tmp);

    if(pell(N,fraction.period[0],D) == 0)
    {
      mpz_set(x,N);
      return 0;
    }
    mpz_set(tmp,N1);
    mpz_set(N1,N);
    mpz_set(N2,tmp);
    mpz_set(tmp,D1);
    mpz_set(D1,D);
    mpz_set(D2,tmp);
    i++;
  }
}

int main()
{
  contFrac A0[1001];
  Period(A0);
  mpz_t x;
  mpz_t max;
  mpz_init(x);
  mpz_init(max);
  int max_D;

  for(int D=2;D<=1000;D++)
  {
    if(sqrt(D)==floor(sqrt(D))) continue;
    convergentFraction(A0[D-1],x);
    if(mpz_cmp(max,x)==-1) 
    {
      mpz_set(max,x);
      max_D = D;
    }
  }
  printf("%d\n",max_D);
  return 0;
}
