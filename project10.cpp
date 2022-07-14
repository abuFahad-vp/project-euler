#include <bits/stdc++.h>

using namespace std;

void SieveOfEratosthenes(int n)
{
	// Create a boolean array
	// "prime[0..n]" and initialize
	// all entries it as true.
	// A value in prime[i] will
	// finally be false if i is
	// Not a prime, else true.
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (int p = 2; p * p <= n; p++)
	{
		// If prime[p] is not changed,
		// then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples
			// of p greater than or
			// equal to the square of it
			// numbers which are multiple
			// of p and are less than p^2
			// are already been marked.
			for (int i = p * p; i <= n; i += p)
				prime[i] = false;
		}
	}
    ofstream myfile;
    myfile.open("out.txt");

	// Print all prime numbers
    long long sum = 0;
	for (int p = 2; p <= n; p++)
		if (prime[p])
        {
            sum += p;
            myfile << p << ", Current sum = "<< sum << "\n";
        }

			
            
    myfile.close();
}

// Driver Code
int main()
{
	int n = 10;

	SieveOfEratosthenes(2000000);
	return 0;
}
