using Primes

function initialize_dict(len)
    d = Dict()
    for i in 0:1:len
        d[i] = 0
    end
    return d
end

function main()
    target = 2
    while(true)
        elements = primes(target)
        len = length(elements)
        ways = initialize_dict(target+1)
        ways[0] = 1
        for p in elements
            for i in p:target
                ways[i] += ways[i-p]
            end
        end
        if(ways[target] >= 5000) 
            println("$target = ",ways[target])
            return 
        end
        target += 1
    end
end

main()
