
using Primes

file = open("range.txt","w")

limitDigits = log10(800800)*800800

len(p,q) = p*log10(q) + q*log10(p)

pList = primes(2,420331)

function Limit(p)
    upper = Int(ceil(800800*log10(800800) / log10(p)))
    lower = upper - Int(floor((p*log10(upper))/log10(p)))
    return lower
end
#
#cache = 0
#for p in pList
#    global cache
#    if len(p,2) > limitDigits
#        break
#    end
#    cache = p
#end
#println(cache)
#
#
for n in pList
    limit = Limit(n)
    p = nextprime(limit)
    #println("$p, $limit")
    flag = true
    while flag
        if len(p,n) > limitDigits
            while true
                if p < n 
                    flag = false
                    break 
                end
                p = prevprime(p-1)
                if len(p,n) <= limitDigits && p > n
                    println(n, " ",p)
                    write(file,"$n $p\n")
                    flag = false
                    break
                end
            end
        end
        p = nextprime(p+1)
    end
end
close(file)
