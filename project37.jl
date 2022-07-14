using Primes
function trun(n)
    if isprime(n) != true
        return false
    end
    a = digits(n)
    #left to write
    popfirst!(a)
    p = 0
    while true
        if(isempty(a))
            break
        end
        p = sum(a[k]*10^(k-1) for k=1:length(a))
        # println("$p")
        if isprime(p) != true
            return false
        end
        popfirst!(a)

    end

    a = digits(n)
    #left to write
    popat!(a,length(a))
    p = 0
    while true
        if(isempty(a))
            break
        end
        p = sum(a[k]*10^(k-1) for k=1:length(a))
        # println("$p")
        if isprime(p) != true
            return false
        end
        popat!(a,length(a))
    end
    return true
end
   
c = 0
s = 0
for i in primes(11,1000000)
    if(trun(i))
        println("$c, $i")
        c += 1
        s += i
    end
end
s
c

