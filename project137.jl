
x1 = 0
y1 = 1

x2 = 2
y2 = 5

x3 = -1
y3 = 2

xn(x,y) = -9*x + 4*y - 2
yn(x,y) = 20*x - 9*y + 4

count = 0
ans = []

while count < 15
    x = xn(x1,y1)
    y = yn(x1,y1)
    if x > 0
        push!(ans,x)
    end
    x1 = x
    y1 = y

    x = xn(x2,y2)
    y = yn(x2,y2)
    if x > 0
        push!(ans,x)
    end
    x2 = x
    y2 = y

    x = xn(x3,y3)
    y = yn(x3,y3)
    if x > 0
        push!(ans,x)
    end
    x3 = x
    y3 = y
    count += 1
end
println(sort(ans)[15])
