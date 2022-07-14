#include <bits/stdc++.h>

using namespace std;


// A function to print all prime
// factors of a given number n
void primeFactors(long long n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

int main(){
    // first solution

    // long long a = 100;
    // vector<long long> factors;

    // if(a%2==0){
    //     factors.push_back(2);
    // }

    // bool isprime = true;
    
    // for(long long i=3;i<sqrt(a);i=i+2){
    //     if(a%i == 0){
    //         for(long long j=2;j<sqrt(i);j++){
    //             if(i%j==0){
    //                 isprime = false;
    //                 break;                    
    //             }
    //         }
    //         if(isprime){
    //             factors.push_back(i);
    //         }
    //     }
    // }

    // 2nd One specific for the solution

    // for(long long i=2;i<sqrt(a);i++){
    //     if(a%i == 0){
    //         factors.push_back(i);
    //         a /= i;
    //     }
    // }
    // if(a>2){
    //     factors.push_back(a);
    // }
    // for(auto x:factors){
    //     cout << "i = " << x << '\n';
    // }
    // cout << "largest prime is " << factors.back() << '\n';

    // long long num = 600851475143;
    // long long aux = 2;
    // while(num!=1){
    //     if(num%aux==0){
    //         num /= aux;
    //     }else{
    //         aux++;
    //     }
    // }
    // cout << aux << '\n';
    primeFactors(45005485100547);

    return 0;
}