

function power(a,b)
    n = big(1)
    while b>0
       n *= a
       b -= 1 
    end 
    return n
end

su = 0

for a in 90:99
    for b in 90:99
        tmp = sum(digits(power(a,b)))
        if su < tmp
            su = tmp
        end
    end
end

su
