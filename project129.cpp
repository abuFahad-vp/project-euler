
#include <bits/stdc++.h>
#include <algorithm>
#include <math.h>
#include <gmp.h>

using namespace std;

void repunit(double k, mpz_t ones) {
    mpz_set_ui(ones,10);
    mpz_pow_ui(ones,ones,k);
    mpz_sub_ui(ones,ones,1);
    mpz_div_ui(ones,ones,9);
}

int main2() {
    mpz_t ones;
    mpz_init(ones);
    double n = 1000000;
    double max = 0;
    while(true) {
        if (fmod(n,5) == 0) {
            n += 2;
            continue;
        }
        if (max > 1000000) {
            break;
        }
        int k = 1;
        while(true) {
        // for(int k=1;k<10000;k++) {
            repunit(k,ones);
            mpz_mod_ui(ones,ones,n);
            cout  << n << " " << k << '\n';
            if(mpz_cmp_ui(ones,0) == 0 && __gcd((int)n,10) == 1) {
                cout  << n << " " << k << '\n';
                if(max < k) {
                    max = k;
                }
                break;
            }
            if(k>n) break;
            k++;
        }
        n += 2;
    }
    return 0;
}

int main() {
    mpz_t ones;
    mpz_init(ones);
    repunit(1000002,ones);
    mpz_mod_ui(ones,ones,1000003);
    gmp_printf("%Zf\n",ones);
}

int main3() {
    mpz_t ones;
    mpz_init(ones);
    double limit = 1000000;
    double n = limit + 1;
    double max = 0;
    double k = n - 10;
    while(true) {
        if (max > 1000000) {
            break;
        }
        while(true) {
            repunit(k,ones);
            mpz_mod_ui(ones,ones,n);
            cout << fixed;
            if(mpz_cmp_ui(ones,0) == 0 && __gcd((int)n,10) == 1){
                cout <<  n << " " << k << '\n';
                if(max < k) {
                    max = k;
                }
                break;
            }
            if(k>n+10) break;
            k++;
        }
        n += 2;
    }
    return 0;
}