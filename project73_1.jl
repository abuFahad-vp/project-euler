limit = 45
result = 0
a = []

for d in 1:limit
    for n in 1:d
        if gcd(n,d) == 1 && n/d > 1/3 && n/d < 1/2
            push!(a,d)
            result += 1
        end
    end
end

a |> sort
# println(a)
result