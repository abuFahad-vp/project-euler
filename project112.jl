
function isbouncy(n::Int64)
    o::Vector{Int64} = digits(n)
    d1::Vector{Int64} = sort(o)
    d2::Vector{Int64} = sort(o;rev=true)
    if d1 == o || d2 == o
        return true
    end
    return false
end

num = 100
not_b = 0
while true
    if !isbouncy(num) 
        not_b += 1
        if (not_b/num)*100 == 99.0
            println(num)
            break
        end
    end
    num += 1
end
