using Combinatorics


function main()


    S::Vector = [11, 18, 19, 20, 22, 25]
    # S::Vector = [310, 465, 543, 582, 602, 613, 620, 621, 622, 624, 627]
    # n = 12
    # S::Vector = [613, 923, 1078, 1156, 1195, 1215, 1226, 1233, 1234, 1235, 1237, 1240]
    # b = 613
    # S .+= b
    # pushfirst!(S,b)
    # println(S)

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