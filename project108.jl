using Primes

i = 2
while true
    num_of_factor = 1
    for fac in values(factor(i*i))
        num_of_factor *= (fac+1)
    end
    num_of_factor += 1
    num_of_factor /= 2
    if num_of_factor > 1000
        println("$num_of_factor, $i, $(i*i)")
        break
    end
    i += 1
end
