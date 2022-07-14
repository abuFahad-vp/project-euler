
f(n) = sum(factorial.(digits(n)));
sf(n) = sum(digits(n))

# g(i) = n
# sf(n) = i

sf(f(25))
sf(f(52))

# g(5) = 25
# sf(25) = 5
# f(x) = 25

f_s = f.(1:25)

g_s = Dict()

for i in 1:25

    println("$i -> ", sf(f_s[i]))

    if(!(i in keys(g)))
        g_s[i] = sf(f_s[i])
    end

end

function g(n)
    return g_s[n]
end

