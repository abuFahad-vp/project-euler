

sq(n) = Int64((n*(n+1)*(2*n+1))/6)
isPalindrome(n) = (digits(n) == reverse(digits(n)))

ans = Set()

for n in 1:4000
    for m in 0:n-2
        pal = sq(n)-sq(m)
        if isPalindrome(pal) && pal < 10^8
            push!(ans,pal)
        end
    end
end

sum(ans)