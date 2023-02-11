
function permution(n,r)
    return (factorial(big(n)) / factorial(big(n-r)))
end

# only one type of block
function comb(lenOfBlock, space, numberOfBlocks)
    return binomial(space-(numberOfBlocks*lenOfBlock)+numberOfBlocks,numberOfBlocks)
end

# only 2 type of block
function perm(space,numberOfRed, numberOfGreen, numberOfBlue, totalNumberOfBlocks)
    return permution(space-(2*numberOfRed + 3*numberOfGreen + 4*numberOfBlue) + totalNumberOfBlocks,totalNumberOfBlocks)
end

space = 7
ans = 0

for r in 0:1:space
    for g in 0:1:space
        for b in 0:1:space
            totalNumberOfBlocks = 3
            if r == 0 totalNumberOfBlocks -= 1 end
            if g == 0 totalNumberOfBlocks -= 1 end
            if b == 0 totalNumberOfBlocks -= 1 end
            if 2*r + 3*g + 4*b <= space
                ans += BigInt(perm(space,r,g,b,totalNumberOfBlocks))
            end
        end
    end
end


# red block
for i in 1:Int(floor(space/2))
    ans += comb(2,space,i)
end

# green block
for i in 1:Int(floor(space/3))
    ans += comb(3,space,i)
end

# blue block
for i in 1:Int(floor(space/4))
    ans += comb(4,space,i)
end

println(ans)

# a,b,c,d,n = 0,0,0,1,50

# for i in 1:50
#     a,b,c,d = b,c,d,(a+b+c+d)
# end

# d

# # M = [0 1 0 0;
# 0 0 1 0;
# 0 0 0 1;
# 1 1 1 1]

# N = M^50
# println(N[4,4])