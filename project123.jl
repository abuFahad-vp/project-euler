
using Primes
pset = primes(1000000)
n = 1
while (2*n*pset[n]) < 10^10
    n += 2
end
println(n)


       