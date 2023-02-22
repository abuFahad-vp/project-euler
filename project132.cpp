
#include <iostream>
#include <vector>

// return (base^exponent) % modulo
using namespace std;

unsigned int powmod(unsigned int base, unsigned int exponent, unsigned int modulo)
{
  unsigned int result = 1;
  while (exponent > 0)
  {
    // fast exponentation:
    // odd exponent ? a^b = a*a^(b-1)
    if (exponent & 1)
      result = (result * (unsigned long long)base) % modulo; // enforce 64-multiplication

    // even exponent ? a^b = (a*a)^(b/2)
    base = (base * (unsigned long long)base) % modulo;       // enforce 64-multiplication
    exponent >>= 1;
  }
  return result;
}

int main() {
    cout << powmod(100,1000000001,17) << '\n';
}

int main2()
{
  unsigned int numFactors = 40;
  unsigned long long digits = 1000000000;
//   std::cin >> digits >> numFactors;

  unsigned int sum = 0;
  std::vector<unsigned int> primes = { 2 }; // two is never a prime factor of a repunit
  for (unsigned int i = 3; numFactors > 0; i++)
  {
    bool isPrime = true;

    // test against all prime numbers we have so far (in ascending order)
    for (auto x : primes)
    {
      // prime is too large to be a divisor
      if (x*x > i)
        break;

      // divisible => not prime
      if (i % x == 0)
      {
        isPrime = false;
        break;
      }
    }

    // no prime
    if (!isPrime)
      continue;

    primes.push_back(i);

    // check for divisibility by 9*prime
    auto modulo = 9 * i;
    // remainder must be 1
    auto remainder = powmod(10, digits, modulo);
    if (remainder == 1)
    {
      sum += i;
      numFactors--;
    }

    // don't analyze huge primes
    // => not needed for the original problem, but avoids malicious input in live test
    // => e.g. user asks for more primes than the repunit has
    if (i > 1111111)
      break;
  }

  std::cout << sum << std::endl;

  return 0;
}
