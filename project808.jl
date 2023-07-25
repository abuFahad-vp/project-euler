@time begin
using Primes

function reverses(num)
    rev = 0
    while num > 0
        rev = rev*10 + num%10
        num = floor(num/10)
    end
    return Int(rev)
end

ans = []

function rec(current,numDigits,pattern,place,ans)
    if numDigits == 0
        p = 1*10^(place-1) + current*10 + pattern
        try 
            value = Int(sqrt(reverses(p*p)))
            if isprime(p) && isprime(value) && value != p
                push!(ans,p*p)
                if pattern == 3
                    push!(ans,value*value)
                end
            end
        catch 
        end
    else
        for x in 0:3
            rec(current*10+x,numDigits-1,pattern,place,ans)
        end
    end
end

for i in 2:8
    rec(0,i-2,1,i,ans)
    rec(0,i-2,3,i,ans)
end

println(sum((ans)[1:50]))
end
