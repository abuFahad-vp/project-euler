
using Primes,Combinatorics

function pan(n)
    l = digits(n)
    o = intersect(l,l)
    if l==o
        l = sort(l)
        if l[1] == 0
            return 0
        end
        for i in 1:length(l)
            if l[i] != i
                return 0
            end
        end       
        return length(l)
    end
    return 0
end

len = 0
curr = 0
for i in primes(10000000)
    if pan(i) >= len
        len = pan(i)
        curr = i
    end
end

println(curr)

#8 and 9 can't. bcz the sum of 9&8 is divisible by 3
# So 7 will be the next choice
# permutations of all 7 digits and check its primes
function solutionB()
  nbase = "123456789"
  maxp = 0

  for nd = 7:-1:4
    for pr in Combinatorics.permutations(nbase[1:nd])
      n = parse(Int, join(pr))
      
      if Primes.isprime(n) && (n > maxp)
        maxp = n
        # println(n)
      end
    end
    (maxp > 0) && break
  end
  maxp
end

solutionB()