using Primes

# this block only change one digit and 0,2,8 excluded because there M(10,d) != 9
primeSet = Set()

for g in 1:9
    for i in 0:1:9
        for k in 10:-1:1
            if i== 0 && k == 1 continue end
            str = ["$g" for s in 1:10]
            popat!(str,k)
            insert!(str,k,"$i")
            p = parse(Int128,join(str))
            if isprime(p)
                push!(primeSet,p)
            end
        end
    end
end

#for 0
for i in 1:9
    for k in 1:9
        p = i*10^9 + k
        if isprime(p)
            push!(primeSet,p)
        end
    end
end

# for 2, 8
for a in [2,8]
    for i in 0:1:9
        for k in 0:1:9
            for g in 10:-1:1
                for q in 10:-1:1
                    str = ["$a" for s in 1:10]
                    popat!(str,g)
                    insert!(str,g,"$i")
                    popat!(str,q)
                    insert!(str,q,"$k")
                    p = parse(Int128,join(str))
                    if isprime(p) && p > 1000000000
                        push!(primeSet,p)
                    end
                end
            end
        end
    end
end
println(sum(primeSet))

