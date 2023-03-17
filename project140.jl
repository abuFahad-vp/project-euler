
x1 = 2
y1 = -7

x2 = 0
y2 = -1

x3 = -4
y3 = 5

x4 = -3 
y4 = 2

x5 = 0
y5 = 1

x6 = -3
y6 = -2

xn(x,y) = -9*x - 4*y - 14
yn(x,y) = -20*x - 9*y - 28

count = 0
ans = 0

while count < 10
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

    x = xn(x4,y4)
    y = yn(x4,y4)
    if x > 0
        push!(ans,x)
    end
    x4 = x
    y4 = y

    x = xn(x5,y5)
    y = yn(x5,y5)
    if x > 0
        push!(ans,x)
    end
    x5 = x
    y5 = y

    x = xn(x6,y6)
    y = yn(x6,y6)
    if x > 0
        push!(ans,x)
    end
    x6 = x
    y6 = y

    count += 1
end

sum((ans)[1:30])
