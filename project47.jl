
using Primes
n = 2
while true
    if length(factor(Set,n))==4 && length(factor(Set,n+1))==4 && length(factor(Set,n+2))==4 && length(factor(Set,n+3))==4
        break
    end
    n += 1
end
n
