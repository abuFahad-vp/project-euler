
ans = 0
for m in 1:20^3
    for n in 1:m-1
        if gcd(m,n) == 1 && ((iseven(m) && isodd(n)) || (iseven(n) && isodd(m)))
            a = m^2 - n^2
            b = 2*m*n
            c = m^2 + n^2
            smallArea = abs(b-a)
            if c^2 % smallArea == 0
                n = Int(floor(10^8/(a+b+c)))
                ans += n
            end
        end
    end
end
ans