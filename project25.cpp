/* Another Solution
Fibonacci terms converge to (n)*Phi=(n+1), where Phi is the
 Golden Ratio (1+sqrt5)/2.
I reasoned that there is an nth term that is smaller than 10^999
 with the corresponding nth+1 term bigger than 10^999.
So, using the binary splitting method for searching, I used
 the MS calculator and found Phi^4780<10^999 and Phi^4781>10^999.
Since the two initial terms of the series have the same value
 by definition, you have to add one to the exponents found.
No code necessary.
Rudy.
*/

#include <bits/stdc++.h>
#include <gmpxx.h>
#include <gmp.h>

using namespace std;


unsigned long len(mpz_t num)
{
    mpz_t tmp;
    mpz_init(tmp);
    mpz_set(tmp,num);
    unsigned long n =0;
    while(1)
    {
        if(mpz_get_ui(tmp)==0)
        {
            break;
        }
        mpz_div_ui(tmp,tmp,10);
        n++;
    }
    return n;
}

int main()
{
    mpz_t curr;
    mpz_t prev;
    mpz_t tmp;mpz_init(tmp);

    mpz_init_set_str(curr,"1",10);
    mpz_init_set_str(prev,"1",10);
    int c=3;
    while(c<10000)
    {
        mpz_mul_ui(tmp,curr,1);
        mpz_add(curr, curr,prev);
        mpz_mul_ui(prev,tmp,1);
        if(len(curr)>=1000)
        {
            printf("%d\n", c);
            break;
        }
        c++;
    }
}