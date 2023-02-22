
using FastPrimeSieve

primes = FastPrimeSieve.small_primes(100000) # starting from 7

function A(n)
    x = 1
    for k in 1:n
        x *= 10
        x %= 9*n
        if x == 1
            return k
        end
    end
	return -1
end

ans = 0
g = BigInt(10)^30

for p in primes
    z = A(p) 
    if gcd(z,g) == z
        ans += p
    end
end

sum(primes) - ans + 2 + 3 + 5
