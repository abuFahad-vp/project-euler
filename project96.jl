
function isOdd(n)
    for i in digits(n)
        if i%2==0
            return false
        end
    end
    return true
end

function reverse(n)
    r = 0
    for i in n
        r = r*10 + i
    end
    return r
end

function main()
    c = 0
    for x in 12:1000000000
        d = digits(x)
        if d[1] == 0 || d[length(d)] == 0 continue end
        a = reverse(d)
        g = a+x
        if isOdd(g)
            println("$x, $a, $g")
            c += 1
        end
    end
    println(c)
end

@time main()

