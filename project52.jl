

function issame(n)
    return sort(digits(n))==sort(digits(2*n))==sort(digits(3*n))==sort(digits(4*n))==sort(digits(5*n))==sort(digits(6*n))
end

c = 1
while true
    if issame(c)
        println(c)
        break
    end
    c += 1
end