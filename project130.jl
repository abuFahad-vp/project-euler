
using Primes

function foo(n)
    x = 1
    for k in 1:n
        x *= 10
        x %= 9*n
        if x == 1
            return k
        end
    end
end

index = 1
n = 91
ans = 0
while true
    if index > 25 break end
    if n % 2 != 0 && n % 5 != 0 && gcd(n,10) == 1
        if (n-1) % foo(n) == 0 && !isprime(n)
            println("$index = $n")
            ans += n
            index += 1
        end
    end
    n += 1
end

ans