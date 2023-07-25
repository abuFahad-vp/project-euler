#include <gmp.h>

void Sn(mpz_t result, mpz_t n,mpz_t modulus) {
    mpz_t ten;
    mpz_t temp;
    mpz_init(temp);
    mpz_init_set_ui(ten,10);
    
    mpz_powm(result,ten,n,modulus);
    mpz_mul_ui(result,result,6);
    mpz_mod(result,result,modulus);

    mpz_mod(temp,n,modulus);
    mpz_mul_ui(temp,temp,9);
    mpz_mod(temp,temp,modulus);
    mpz_sub(result,result,temp);
    mpz_sub_ui(result,result,6);
    mpz_mod(result,result,modulus);
}

void sn(mpz_t result,mpz_t n,mpz_t modulus) {
    mpz_t ten;
    mpz_t temp;
    mpz_init(temp);
    mpz_init_set_ui(ten,10);
    
    mpz_mod_ui(result,n,9);
    mpz_add_ui(result,result,1);
    mpz_fdiv_q_ui(temp,n,9);
    mpz_powm(temp,ten,temp,modulus);
    mpz_mul(result,result,temp);
    mpz_sub_ui(result,result,1);
    mpz_mod(result,result,modulus);
}

void calculate(mpz_t result, mpz_t n,mpz_t modulus) {
    //20
    mpz_t S,s;
    mpz_t result_s;
    mpz_t result_t;

    mpz_init(S);
    mpz_init(s);
    mpz_init(result_s);
    mpz_init_set_ui(result_t,0);

    mpz_fdiv_q_ui(S,n,9);
    Sn(result,S,modulus);

    // sudden next of 
    mpz_mul_ui(s,S,9);
    mpz_add_ui(s,s,1);

    while(true) {
        if(mpz_cmp(s,n) > 0) {
            break;
        }
        sn(result_s,s,modulus);
        mpz_add(result_t,result_t,result_s);
        mpz_add_ui(s,s,1);
    }
    mpz_mod(result_t,result_t,modulus);
    mpz_add(result,result,result_t);
    mpz_mod(result,result,modulus);
}

int main() {

   mpz_t n;
   mpz_t result;
  // mpz_t ans;
   mpz_t modulus;

   mpz_init_set_str(modulus,"1000000007",10);
   mpz_init(result);
   mpz_init_set_ui(n,1012341230000);
    mpz_t ten;
    mpz_init_set_ui(ten,10);
    
    mpz_powm(result,ten,n,modulus);
    gmp_printf("%Zd\n",result);

  // mpz_init_set_ui(ans,0);

  // calculate(result,n,modulus);

  // unsigned long f1 = 0;   
  // unsigned long f2 = 1;   
  // unsigned long fn = 0;   
  //                         
  //for(int i=2;i<=90;i++) {
  //    fn = f1+f2;
  //    mpz_set_ui(n,fn);
  //    calculate(result,n,modulus);
  //    mpz_add(ans,ans,result);
  //    f1 = f2;
  //    f2 = fn;
  //}
  //mpz_mod(ans,ans,modulus);
  //gmp_printf("%Zd\n",ans);
}
