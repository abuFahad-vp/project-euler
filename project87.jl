using Primes

prime = primes(2,7072)

len = length(prime)

n = Set()

for i in prime
    for j in prime
        for k in prime
            sum = i^2 + j^3 + k^4
            if sum > 50000000 break end
            push!(n,sum)
        end
    end
end

println(length(n))

