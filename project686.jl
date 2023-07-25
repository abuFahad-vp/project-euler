
function P(d)
    descr = (d-3)           * log2(10)
    l     = (ceil(descr  + log2(123)))
    r     = Int(floor(descr + log2(124)))
    if (r == l)
        return r
    end
    return 0
end

c = 0
for i in 1:100000000
    global c
    v = P(i)
    if v != 0
        c += 1
        if c == 678910
            println(c, " " ,v)
            break
        end
    end
    i += 1
end
