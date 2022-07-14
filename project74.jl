
function fac_sum(n)
    c = 1
    new = n
    d = []
    while true 
        new = sum(factorial.(digits(new)))
        if new in d 
            return c 
        end
        push!(d,new)

        c += 1
    end
end

c = 0
for i in 1:1000000
    if fac_sum(i) == 60
        c += 1
    end
end
c
