
#revere and add

function undigitise(n)
    sum = 0
    d=1
    for i in length(n):-1:1
        sum = sum + n[d]*(10^(i-1))
        d += 1
    end
    return sum
end

function islechrel(n)
    n = big(n)
    num = big(1)
    max = 0
    while max < 52
        num = n + undigitise(digits(n))
        if num == undigitise(digits(num))
            return false
        else
            n = num
        end
        max += 1
    end
    return true
end

c = 0
for i in 1:10000
    if islechrel(i)
        c += 1
    end
end
c