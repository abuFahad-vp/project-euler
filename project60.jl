using Primes

concatenate(a,b) = BigInt(a*10^(floor(log10(b)) + 1) + b)

function comp(a,b)
    if isprime(concatenate(a,b)) && isprime(concatenate(b,a))
        return true
    end
    return false
end

function solve()
    upper = 10000
    p = primes(upper)
    for a in p
        for b in p
            if b < a
                continue
            end
            if comp(a,b)
                for c in p
                    if c < b
                        continue
                    end
                    if comp(a,c) && comp(b,c)
                        for d in p
                            if d < c
                                continue
                            end
                            if comp(a,d) && comp(b,d) && comp(c,d)
                                for e in p
                                    if e < d
                                        continue
                                    end
                                    if comp(a,e) && comp(b,e) && comp(c,e) && comp(d,e)
                                        println("$a $b $c $d $e -> $(a+b+c+d+e)")
                                        return
                                    end
                                end
                            end
                        end
                    end
                end
            end
        end
    end
end

solve()
                