#include <stdio.h>
#include <gmp.h>


void discr(mpz_t a,mpz_t b,mpz_t c, mpz_t r)
{
  mpz_t tmpb;
  mpz_init(tmpb);
  mpz_t tmpac;
  mpz_init_set_ui(tmpac,1);
  //b^2
  mpz_mul(tmpb,b,b);
  gmp_printf("%Zd\n",tmpb);
  //4*a*c
  mpz_mul_ui(tmpac,tmpac,4);
  mpz_mul(tmpac,a,c);
  gmp_printf("%Zd\n",tmpac);

  mpz_sub(tmpb,tmpb,tmpac);

  mpz_sqrt(r,tmpb);

}

int main()
{
  mpz_t a;
  mpz_t b;
  mpz_t c;
  mpz_t r;
  mpz_init_set_ui(a,1);
  gmp_printf("%Zd\n",a);
  mpz_init_set_ui(b,-5);
  mpz_init_set_ui(c,6);
  mpz_init(r);

  discr(a,b,c,r);

  gmp_printf("%Zd\n",r);

}

