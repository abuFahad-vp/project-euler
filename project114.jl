using Combinatorics

# function comb(space,i,k)
#     n = space-(i+k) + 2
#     if i == k
#         return binomial(n,2) - binomial(n-1,1)
#     end
#     return binomial(n,2)*2 - binomial(n-1,1)*2
# end

# ans = 0
# for i in 3:24
#     for k in i+1:49-i
#         ans += comb(50,i,k)
#     end
# end

# println(ans)

function combs(blocks, isPrint=false)

    set = Set(collect(permutations(blocks)))

    if isPrint
        for x in set
            println(x)
        end
        println("----------------------------")
    end
    len = length(blocks)
    count = length(set)
    println("Total length of Set without removing the group blocks = $count")

    for c in set
        flag = true
        for x in 1:len-1
            if c[x] * c[x+1] != 0
                count -= 1
                flag = false
                break
            end
        end
        if flag println(c) end
    end
    println("Total length of Set with removing the group blocks = $count")
    
end


block = [1,2,0,0,3]
combs(block,true)
# binomial(4,2) - binomial(3,1)