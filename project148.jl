

using Combinatorics

function newC(n,r)
    n1 = BigInt(1)
    n2 = BigInt(1)
    rC = 1
    for i = n:-1:r+1
        n1 *= i
        n2 *= rC
        rC += 1
        println(n1," ",n2)
    end
end

newC(69,5)

count = 0
for n in 0:100
    each = 0
    for r = 0:1:n
        pascal = newC(n,r)
        println(pascal)
        if pascal % 7 != 0
            count += 1
            each += 1
        end
    end
    println("$n = $each")
end
count 


