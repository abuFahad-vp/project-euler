using Primes

function sumTheFactors(n::Int64)
    factors = factor(Dict,n)
    multiTerms = 1
    for i in keys(factors)
        sumTerms = 0
        for k in 0:factors[i]
            sumTerms += i^k
        end
        multiTerms *= sumTerms
    end
    return multiTerms-n
end


function main()
    n = 1
    max = 0
    while true
        if n > 1000000 break end 
        tmp = sumTheFactors(n)
        count = 1
        list = Vector()
        append!(list,n)
        prev = -1
        while true
            if tmp > 1000000 break end
            if isprime(tmp) break end
            if tmp == n 
                if max < count 
                    max = count
                    println(list ," : count = $count")
                    break 
                end
            end
            if tmp in list
                break 
            end
            append!(list,tmp)
            count += 1
            prev = tmp
            tmp = sumTheFactors(tmp)
        end
        n += 1
    end
end

main()