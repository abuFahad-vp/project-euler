
using Primes

array = []
for n in 1:100000
    push!(array,[n,prod(factor(Set,n))]) 
end

sort(array,by=x->x[2])[10000][1]






