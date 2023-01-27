using Combinatorics

function readArray()
    file = open("project105.txt","r")
    str = readlines(file)
    arrays = []
    for i in str
        append!(arrays,[parse.(Int64,split(i,","))])
    end
    return arrays
end


function main()
    total = 0
    for S in readArray()
        ans = collect(powerset(S))
        popfirst!(ans)
        len = length(ans)
        # println(ans)

        ifAny = true
        for i = 1:len
            for k = 1:len
                if length(ans[i] ∩ ans[k]) == 0
                    if sum(ans[i]) == sum(ans[k]) ifAny = false; break end
                    if length(ans[i]) > length(ans[k]) && sum(ans[i]) < sum(ans[k]) ifAny = false; break end
                end
            end
        end
        if ifAny total += sum(S) end
    end
    println(total)
end

@time main()
