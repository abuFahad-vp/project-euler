
function max_r(n::Int64)
    b = 1
    l = Any[]
    c = 0
    while true
        mod = b%n
        if(mod in l)
            return c
        end
        push!(l,mod)
        b = mod*10
        c += 1
    end
    return 0
end

f = 0
for i in 1:1000
    if(f<max_r(i))
        f = i
    end
end
f