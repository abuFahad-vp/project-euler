
#include <bits/stdc++.h>
#include <gmp.h>

using namespace std;

typedef unsigned long long ull;

//initialize result to 1
void C(ull n, ull r, mpz_t result) {
    mpz_t din;
    mpz_set_ui(result,1);
    mpz_init_set_ui(din,1);
    ull rc = 1;
    for(int i=n;i>r;i--) {
        mpz_mul_ui(result,result,i);
        mpz_mul_ui(din,din,rc);
        rc++;
    }
    mpz_div(result, result, din);
}


int main(){
    ull limit = 1000000000;
    ull sum = 0;
    int n = floor(log(limit)/log(7));
    int prevIncrement = 1;
    for(;n>=0;n--) {
        int currentMultiple = floor(limit/pow(7,n));
        for(int i=1;i<=currentMultiple;i++) {
            sum += pow(28,n)*i*prevIncrement;
        }
        prevIncrement *= (currentMultiple+1);
        limit -= pow(7,n)*currentMultiple;
    }
    cout << sum << '\n';
}

int main2() {
    mpz_t result;
    mpz_init_set_ui(result,1);

    int count = 0;
    int total = 0;
    int sum = 0;
    for(int n=0;n<2401;n++) {
        int each = 0;
        for(int r=0;r<=n;r++) {
            C(n,r,result);
            // gmp_printf("%Zd ", result);
            mpz_mod_ui(result,result,7);
            if(mpz_cmp_ui(result,0) != 0) {
                count++;
                each++;
            }
            total++;
        }
        cout << n << " = " << each << '\n';
        sum += each;
        if((n+1)%7==0) {
            cout << '\n' << sum << " " << count << '\n' << "-----------------------------------\n";
            sum = 0;
        }
        
    }
    cout << "ans = " << count << " total = " << total << '\n';
    return 0;
}