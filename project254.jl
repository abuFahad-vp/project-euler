using DataStructures

function factSum(n)

    d = 0
    for i in n
        d += factorial(i)
    end
    return sum(digits(d))
end


function main3()

    g_s = Dict()
    for i in 1:10000000
        gs = factSum(digits(i))

        if gs in keys(g_s) && i > g_s[gs]
            continue
        end

        if gs > 150
            continue
        end
        g_s[gs] = i
    end

    for i in sort(collect(keys(g_s)))
        println("$i - > $(g_s[i]) -> $(sum(digits(g_s[i])))")
    end
end

@time main3() 
