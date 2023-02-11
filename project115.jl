
function blocks(m,n)
    ways = zeros(Int128,n+1)
    for i in 1:m
        ways[i] = 1
    end

    for k in m+1:n+1
        ways[k] = ways[k-1] + sum(ways[1:k-1-m]) + 1
    end
    return ways[n+1]
end

n = 51
while true
    if blocks(50,n) > 1000000 println(n);break end
    n += 1
end