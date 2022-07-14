using  Primes

max = 0
curr = 0
for i in 1:1000000
    r = i/totient(i)
    if max <= r
        max = r
        curr = i
    end
end
curr

# alternate method:- a number with So with that I figured out that for n/phi(n) to be max, it would be the product of all the primes, so voila

largest_value = 2*3*5*7*11*13*17

