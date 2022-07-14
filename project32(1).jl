using OrderedCollections
function ispan(m1,m2)
    n = 1:9
    p = m1*m2
    l = digits(p)
    for i in digits(m1)
        push!(l,i)
    end
    for i in digits(m2)
        push!(l,i)
    end
    l = sort(l)
    return l==n

end
a = OrderedSet()
for i in 1:2000
    for j in 1:2000
        if ispan(i,j)
            push!(a,i*j)
        end
    end
end

println(sum(a))