    
using FastPrimeSieve

primes = FastPrimeSieve.small_primes(1000003)

pushfirst!(primes,5)

ans = 0

function solveX(p1,p2,lenOfp1)
    g = gcdx(10^lenOfp1,p2)[2]*(p2-p1)
    if g < 0
        x = 0-floor(g/p2)
        g = g+p2*x
    else
        x = floor(g/p2)
        g = g-p2*x
    end
    return (g*10^lenOfp1 + p1)
end

for index in 1:lastindex(primes)-1
    p1 = primes[index]
    p2 = primes[index+1]
    len = Int(floor(log10(p1)) + 1)
    value = Int128(solveX(p1,p2,len))
    ans += value
end
ans