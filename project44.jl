function ispen(n)
    if n<=0
        return false
    end
    disc = (1+sqrt(1+(24*n)))/6
    return isinteger(disc)
end
function pen_gen(len)
    pen = []
    for i in len:-1:1
        push!(pen,(i*((3*i)-1))/2)
    end
    return pen
end

j = pen_gen(3000)
k = j 
for a in j
    for b in k
        if ispen(a+b) && ispen(a-b)
            println("$(Int(a-b))")
        end
    end
end


