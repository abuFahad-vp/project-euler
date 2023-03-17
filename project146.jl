
using Primes

n = 10

ans = 0

while n < 150*10^6
    if isprime(n^2+1)
        p = n^2 + 1
        if nextprime(p+1) == (n^2 + 3)
            p = n^2 + 3
            if nextprime(p+1) == n^2 + 7
                p = n^2 + 7
                if nextprime(p+1) == n^2 + 9
                    p = n^2 + 9
                    if nextprime(p+1) == n^2 + 13
                        p = n^2 + 13
                        if nextprime(p+1) == n^2 + 27
                            println(n)
                            ans += n
                        end
                    end
                end
            end
        end
    end
    n += 10
end

println(ans)
