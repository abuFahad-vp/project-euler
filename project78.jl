
function initialize_dict(len)
    d = Dict()
    for i in 0:1:len
        d[BigInt(i)] = BigInt(0)
    end
    return d
end

function main()
    target = BigInt(2)
    while(true)
        ways = initialize_dict(target+1)
        ways[BigInt(0)] = BigInt(1)
        for p in 1:target
            for i in p:target
                ways[BigInt(i)] = ways[BigInt(i)] + BigInt(ways[i-p])
            end
        end

        println("$target = ",ways[target])
        if(ways[target] % 1000000 == 0) 
            println("$target = ",ways[target])
            return 
        end
        target += 1
    end
end

function main2()
    target = 1
    while(true)
        ways = initialize_dict(target+1)
        ways[0] = 1
        for p in 1:target
            for i in p:target
                ways[i] = BigInt(ways[i]+ways[i-p])
            end
        end
        println("$target = ",ways[target])
        if ways[target] % 1000000 == 0
            println("$target = ",ways[target])
            return
        end
        target += 1
    end
end
@time main2()

