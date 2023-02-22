
using Primes

function isValid(value,neigh)
    count = 0
    for x in neigh
        if isprime(abs(value-x)) count += 1 end
    end
    return (count == 3)
end

start = 2
prevstart = 1
prev = 1
index = 1
n = 1
limit = 2000
while true

    # start value
    desc = 6*n 
    second = start+ 6*(n) + 6*(n+1) -1
    third = start+desc
    fourth = start+desc+1
    sixth = start + 1
    fifth = start + 6*(n) -1
    if isValid(start,[second,third,fourth,fifth,sixth])
        index += 1
        if index >= limit 
            println("$index : $start = $second $third, $fourth, $fifth, $sixth")
            break
        end
    end

    #end value
    last = start + 6*n - 1
    second = start
    third = prevstart
    fourth = start + 6*n + 6*(n+1)-1
    fifth = start + 6*n + 6*(n+1) - 2
    sixth = start + 6*n + 6*(n+1) - 3

    if isValid(last,[second,third,fourth,fifth,sixth])
        index += 1
        if index >= limit 
            println("$index : $last = $second $third, $fourth, $fifth, $sixth")
            break
        end
    end

   
    prev = start
    prevstart = start
    start = start + 6*(n)
    n += 1
end
