
function comb(lenOfBlock, space, numberOfBlocks)
    return binomial(space-(numberOfBlocks*lenOfBlock)+numberOfBlocks,numberOfBlocks)
end

space = 50
ans = 0

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