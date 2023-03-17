
issquare(x) = (sqrt(x) == floor(sqrt(x)))

function main4()
    ans = 0
    flag = false
    for a in 1:100000000
        b = 1
        if flag break end
        while 4*(b^3) < a^4
            if issquare(a^4 - 4*(b^3))
                d = a^2
                if d > 10^12 
                    flag = true
                    break
                end
                q = Int(floor(d/b))
                r = d % b
                value = sort([b,q,r])
                if (value[3] / value[2]) == (value[2] / value[1])
                    println("$(a^2), $value")
                    ans += a^2
                end
                if a^2 % 90000 == 0
                    println(a^2)
                end
            end
            b += 1
        end
    end
    println(ans)
end


547674002500

function iscube(x)
    cubrt = floor(cbrt(x))
    N = cubrt*cubrt*cubrt
    return (N == x)
end

function main3()
    for t in 1:10
        for m in 1:10
            println(8*t^(6*m))
        end
    end
end

function main2()
    for x in 1:100000
        for y in 1:x-1
            a = x*y
            b = x+y
            if issquare(b) && iscube(a)
                println("$x, $y : $(x+y)")
            end
        end
    end
end

function main1()
    n = 547674002500
    if n > 2000000
        g2Cube = BigInt(n)^3
    else
        g2Cube = n^3
    end
    g2 = n
    for i in 1:Int128(floor(sqrt(g2Cube)))
        if g2Cube % i == 0
            g1 = i
            value = Int128(g1+ g2Cube/i)
            if issquare(value)
                g3 = g1*((g2/g1)^2)
                if g2Cube % g3 == 0 && g2Cube % value != 0 && (g1 < g2 || g1 < g3)
                    println(g1, " ",g2, " ",g3, " ",g2Cube," ",value)
                    break
                end
            end
        end
    end
end

main1()
    


