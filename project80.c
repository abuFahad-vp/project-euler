
#include <stdio.h>
#include <gmp.h>
#include "euler.h"
#include <math.h>


int decimalSum(mpf_t x)
{
  mpz_t y;
  mpz_init(y);

  // covert 100 decimal part to integer part
  for(int i=0;i<100;i++)
  {
    mpf_mul_ui(x,x,10);
  }

  while(1)
  {

    gmp_printf ("%Zf\n\n%.Ff\n",y,x);
    if(mpf_cmp_ui(x,1) > 1)
    {
      break;
    }
    mpz_add_ui(y,y,1);
    mpf_sub_ui(x,x,1);
  }
  gmp_printf ("%Zf\n\n%.Ff\n",y,x);
}

int main()
{
  mpf_t x;

  mpf_init2(x,350);
  mpf_sqrt_ui(x,2);
  //mpf_sub_ui(x,x,floor(sqrt(2)));

  decimalSum(x);

}
