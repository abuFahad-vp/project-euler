
function comp(n,r)
    return factorial(big(n))/(factorial(big(r))*factorial(big(n-r)))
end
c = 0
for n in 1:100
    for r in 1:n
        if comp(n,r) > 1000000
            c += 1
        end
    end
end

c