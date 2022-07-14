
using Primes
sorted_digited = []
pri = primes(1000,10000)
# instead for permutations, just digitized the number and sorted it
# to compare 
for p in pri
    d = digits(p)
    d = sort(d)
    push!(sorted_digited,d)
end

ls = 1
ms = 1
ans = []
# push to ans if the number has same digit and difference is 3330
for l in sorted_digited
    for m in sorted_digited
        if l == m && pri[ms]-pri[ls] == 3330
            push!(ans,[pri[ms], pri[ls]])     
        end
        ms += 1
    end
    ms = 1
    ls += 1
end

#compare the ans if the same element repeated.
for i in ans
    for j in ans
        if i[1]==j[2]
            println("$i, $j")
        end
    end
end


        
