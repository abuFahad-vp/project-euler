function pan(l)
    o = intersect(l,l)
    if l==o
        l = sort(l)
        if l[1] == 0
            return false
        end
        if l==1:9
            return true
        end
    end
    return false
end

re = Any[]
curr = Any[]
for i in 1:20000
    for j in 1:10
        pro = i*j
        for k in digits(pro)
            push!(curr,k)
        end
        if length(curr)==9 && pan(curr)
            ele = [i,j]
            push!(re,ele)
        end
        if length(curr) > 9
            break
        end
    end
    curr = Any[]
end

println("End Re = $re")

for i in re
    for j in 1:i[2]
        print("$(i[1]*j)")
    end
    println()
end
