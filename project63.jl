
c = 0
for i in 1:9
    flag = true
    k = 1
    while flag
        if length(digits(BigInt(i)^k)) == k
            c += 1
        end
        if length(digits(BigInt(i)^k)) < k
            flag =false
            break
        end
        k += 1
    end
end

c
