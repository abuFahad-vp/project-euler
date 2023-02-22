using Primes

count = 0
k = 1
while true
    a = 1 + 3*k*(k+1)
    if a > 10^11 break end
    if isprime(a)
        count += 1
    end
    k += 1
end

count

