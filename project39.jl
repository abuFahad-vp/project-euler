ma = 0
c = 0 
curr_p = 0
for p in 1:1000
    for a in 1:500
        for h in 1:500
            if((2*(a^2)) - 2*(p-h)*a + (p^2 - 2*p*h)==0)
                b = h^2 - a^2
                b = b^0.5
                if a+b+h == p && a^2+b^2 == h^2
                    # println("$a, $b, $h")
                    c += 1
                end
            end

        end
    end
    if ma < c
        ma = c
        curr_p = p
    end
    c = 0
end

println("$ma $curr_p")