using Combinatorics, Primes

p = collect(permutations(a))
new = []
for i in p
    if i[1] != 0
        push!(new,i)
    end
end

function undigitise(n)
    sum = 0
    d=1
    for i in length(n):-1:1
        sum = sum + n[d]*(10^(i-1))
        d += 1
    end
    return sum
end



function check_div(n)
    p = 1
    for i in 2:length(n)-2
        p = nextprime(p+1)
        if (n[i]*100 + n[i+1]*10 + n[i+2]) % p != 0
            return false
        end
    end
    return true
end

s = 0
for l in new
    if check_div(l)==true
        println(l)
        s += undigitise(l)
    end
end

function undigitise(n)
    sum = 0
    d=1
    for i in length(n):-1:1
        sum = sum + n[d]*(10^(i-1))
        d += 1
    end
    return sum
end


s