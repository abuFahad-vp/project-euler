#include <bits/stdc++.h>

using namespace std;


//this method is slow we can use sieve of erasthosanisis
bool isprime(long long num)
{
    for(int i=2;i<num;i++)
    {
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void solve()
{
    ofstream myfile;
    myfile.open("out1.txt");

    bool flag = true;
    int n = 1;
    vector<long long> primes;
    primes.push_back(2);
    primes.push_back(3);


    for(long long i=1;i<17490;i++)
    {
        primes.push_back((6*i)-1);
        primes.push_back((6*i)+1);

    }
    for (auto i:primes)
    {
        if(isprime(i))
        {
            myfile << i << '\n';
            n++;
        }
        
        
    }
    myfile.close();
    
}

int main(){
    solve();
    return 0;
}

// // C++ program to print all primes
// // smaller than or equal to
// // n using Sieve of Eratosthenes
// #include <bits/stdc++.h>
// using namespace std;

// void SieveOfEratosthenes(int n)
// {
// 	// Create a boolean array
// 	// "prime[0..n]" and initialize
// 	// all entries it as true.
// 	// A value in prime[i] will
// 	// finally be false if i is
// 	// Not a prime, else true.
// 	bool prime[n + 1];
// 	memset(prime, true, sizeof(prime));

// 	for (int p = 2; p * p <= n; p++)
// 	{
// 		// If prime[p] is not changed,
// 		// then it is a prime
// 		if (prime[p] == true)
// 		{
// 			// Update all multiples
// 			// of p greater than or
// 			// equal to the square of it
// 			// numbers which are multiple
// 			// of p and are less than p^2
// 			// are already been marked.
// 			for (int i = p * p; i <= n; i += p)
// 				prime[i] = false;
// 		}
// 	}
//     ofstream myfile;
//     myfile.open("out.txt");

// 	// Print all prime numbers
// 	for (int p = 2; p <= n; p++)
// 		if (prime[p])
// 			myfile << p << "\n";
//     myfile.close();
// }

// // Driver Code
// int main()
// {
// 	int n = 500000;

// 	SieveOfEratosthenes(n);
// 	return 0;
// }

