using Primes

function d1(n)
    return (2n-1)^2 - (2*(n-1))
end
function d2(n)
   return (2*(n-1))^2 - (2*(n-1)-1)
end
function d3(n)
    return (2*(n-1))^2+1
end

n = 2
c = 0
while true
    if isprime(Int(d1(n)))
        c += 1
    end
    if isprime(Int(d2(n)))
        c += 1
    end
    if isprime(Int(d3(n)))
        c += 1
    end
    if (c/((n*4)-3)) * 100 < 10
        println("$(c/((n*4)-3) * 100) length = $(2*n - 1)")
        break
    end
    n += 1
end
