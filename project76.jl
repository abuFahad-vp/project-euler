while true
    target = 5
    ways = Array{BigInt}(undef,target+1)
    ways = fill!(ways,0)

    ways[1] = 1

    for i in 2:target
        for j in i:target+1
            ways[j] += ways[j-i+1]
        end
    end
    if (ways[length(ways)] + 1) % 11 == 0
        println(target)
        break
    end
    target += 1
end

