using Primes

for i in 1:9
    for j in 1:9
        c = 0
        for k in 1:9
            # position = *i*j*3
            n = k*10^5 + i*10^4 + k*10^3 + j*10^2 + k*10 + 3
            if isprime(n)
                c += 1
            end
        end
        if c==8
            println(i," ",j)
        end
    end
end

# 2 3
# ie, *2*3*3
# loop through 1 to 9 find the first number, But no need just guessed
 
