
function A(n)
    x = 1
    for k in 1:n
        x *= 10
        x %= 9*n
        if x == 1
            return k
        end
    end
end

for n in 1000001:1000050
    if n % 2 != 0 && n % 5 != 0
        if foo(n) > 1000000
            println(n)
            break
        end
    end
end
