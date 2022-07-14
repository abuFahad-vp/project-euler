function solve()
    max = 0
    area = 0
    for m in 1:100
        for n in 1:100
            if (m*n*(m+1)*(n+1))/4 <= 2*10^6 && max < (m*n*(m+1)*(n+1))/4
                max = (m*n*(m+1)*(n+1))/4
                area = m*n
            end
        end
    end
    return area
end

solve()

function problem(n = 2000000)
    closest = 0
    area = 0
    for a in 1:2isqrt(n)
        for b in 1:a
            rec = (a+1)*(b+1)*a*b/4
            if abs(n - rec) < abs(n - closest)
                closest = rec
                area = a*b
            end
        end
    end
    return area
end            

@time @show problem()
@time @show solve()
