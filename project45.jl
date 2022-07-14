function ispen(c)
    return isinteger((1+sqrt(1+(24*c)))/6)
end
n = 144
while true
    tri = (2*(n^2)) - n
    n += 1 
    if ispen(tri)
        println(tri)
        break
    end
end



(m0, n0) = (165, 285)
(x0, y0) = (6 * m0 - 1, 2 * n0 + 1)

T(x, y) = (2x + 3y, x + 2y)
h(x, y) = ((x + 1) / 6, (y - 1) / 2)


m, n = h(T(T(T(T(x0, y0)...)...)...)...)

n = Int(n)
ans = n * (n + 1) ÷ 2

println(ans)