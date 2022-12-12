
setprecision(350)

s = 0
for i in 1:100
    global s
    x = BigFloat(i)^(1/2)
    if(x==floor(x)) continue end
    for k in 1:100
        x *= 10
    end

    x = BigInt(floor(x))
    x = digits(x)

    x = reverse(x)
    x = x[1:100]
    s += sum(x)
end
println(s)
