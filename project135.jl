
@time begin
function factors(value)
    factors = []
    for i in 1:Int(floor(value^0.5))
        if value % i == 0
            push!(factors,(i, Int64(value/i)))
        end
    end
    return factors
end

function hasTen(value)
    fact = factors(value)
    ans = 0
    for tuple in fact
        a = tuple[1]
        b = tuple[2]
        y = (a+b)/4
        if !isinteger(y) continue end
        x1 = (5*a + b) / 4
        x2 = (5*b + a) / 4
        if isinteger(x1)
            if x1 - 2*y > 0
                ans += 1
            end
        end
        if isinteger(x2)
            if x2 -  2*y > 0
                ans += 1
            end
        end
        if x1 == x2 ans -= 1 end
    end
    if ans == 10 return 1 end
    return 0
end

ans = 0
for i in 1:1000000-1
    ans += hasTen(i)
end
ans
end