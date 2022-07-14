
function sq_sum(n)
    d = digits(n)
    sum = 0
    for i in d
        sum += i^2
    end
    return sum
end

function is89(n)

    while true
        if n==1
            return false
        end
        if n==89
            return true
        end
        n = sq_sum(n)
    end 
end

c = 0

for i in 2:10000000
    if is89(i)
        c += 1
    end
end

c