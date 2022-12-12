
#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <stdbool.h>

#define ll long long

int main()
{
  mpz_t sum;
  mpz_t sum1;
  mpz_t sum2;
  mpz_init(sum);
  mpz_init_set_ui(sum1,1);
  mpz_init_set_ui(sum2,1);
  int i = 3;
  while(1)
  {
    mpz_add(sum,sum1,sum2);
    printf("%d\n",i);
    if(i==32469)
    {
      printf("%d\n",i);
      gmp_printf("%Zd\n",sum);
      break;
    }
    mpz_set(sum2,sum1);
    mpz_set(sum1,sum);
    i++;
  }
}

