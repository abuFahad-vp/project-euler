using Combinatorics


function main()


    # S::Vector = [11, 18, 19, 20, 22, 25]
    # S::Vector = [20, 31, 38, 39, 40, 42, 45]
    # S::Vector = [39,20+39, 31+39, 38+39, 39+39, 40+39, 42+39, 45+39]

    ans = collect(powerset(S))
    popfirst!(ans)
    len = length(ans)
    # println(ans)

    ifAny = true
    for i = 1:len
        for k = 1:len
            if length(ans[i] ∩ ans[k]) == 0
                if sum(ans[i]) == sum(ans[k]) ifAny = false end
                if length(ans[i]) > length(ans[k]) && sum(ans[i]) < sum(ans[k]) ifAny = false end
            end
        end
    end
    if ifAny println(sum(S)) end
end

main()