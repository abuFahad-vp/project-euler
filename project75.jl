

function initDict(limit)
    trip = Dict()
    for i in 1:limit
        trip[i] = 0
    end
    return trip
end

function generateTriplet(m,n)
    a = m^2-n^2
    b = 2*m*n
    c = m^2 + n^2
    return [a,b,c]
end

function main()
    limit = 800000
    triplets = initDict(1500000)
    tripletAll = Set()
    for m in 2:limit
        for n in 1:m
            tri = sort(generateTriplet(m,n))
            if tri[1] == 0 continue end
            if tri[3] > limit break end
            push!(tripletAll,tri)
            for i in 2:limit
                if i*tri[3] > limit break end
                push!(tripletAll,i.*tri)
            end
        end
    end
    for i in tripletAll
        if (sum(i)) > 1500000 continue end
        triplets[sum(i)] += 1
    end
    count = 0
    for i in keys(triplets)
        if triplets[i] == 1 count += 1 end
    end
    println(count)
end

function main2()
    limit = 1500000
    mlimit = Int64(floor((limit/2)^(1/2)))
    triplet = zeros(Int64,limit+1)
    result = 0
    for m in 2:mlimit
        for n in 2:m
            if(m+n)%2==1 && gcd(n,m)==1
                a = m^2-n^2
                b = 2*m*n
                c = m^2+n^2
                p = a+b+c
                while(p<=limit)
                    triplet[p] += 1
                    if triplet[p]==1 result += 1 end
                    if triplet[p]==2 result -= 1 end
                    p += a+b+c
                end
            end
        end
    end
    println(result)
end

@time main2()
