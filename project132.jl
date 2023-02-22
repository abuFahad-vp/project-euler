
using FastPrimeSieve

primes = FastPrimeSieve.small_primes(100000)
function modPow(b::BigInt, e::BigInt, m::BigInt)
  if m == 1
    return 0
  else
    r = BigInt(1)
    b = b % m
    while e > 0
      if e % 2 == 1
        r = (r*b) % m
      end
      b = (b*b) % m
      e = e >> 1 
    end
    return r
  end
end  

ans = 0
index = 0
for p in primes
    if modPow(10,10^60,9*p) == 1
        index += 1
        println(p)
        ans += p
    end
end
sum(primes)-ans+2+3+5

