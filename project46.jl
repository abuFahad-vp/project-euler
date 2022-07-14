using Primes

odd_len = 10000
odd = [(2x-1) for x in 2:odd_len if !isprime(2x-1)]
function isgold(i)
    for p in primes(2,i)
        a = sqrt((i-p)/2)
        if isinteger(a)
            return false
        end
    end
    return true
end

for o in odd
    if isgold(o)
        println(o)
        break
    end
end