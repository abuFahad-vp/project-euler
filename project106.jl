using Combinatorics


function allElementLessThan(B,C)
    len = length(B)
    if sum(B) >= sum(C)
        for i = 1:len
            if B[i] < C[i] return false end
        end
        return true
    else
        return allElementLessThan(C,B)
    end
end

function main()
    S::Vector = [613, 923, 1078, 1156, 1195, 1215, 1226, 1233, 1234, 1235, 1237, 1240] # n = 12
    ans = collect(powerset(S))
    popfirst!(ans)
    len = length(ans)
    needTocheck = 0
    for i = 1:len
        for k = i+1:len
            if length(ans[i]) > length(ans[k])
                B = ans[i]
                C = ans[k]
            elseif length(ans[k]) >= length(ans[i])
                B = ans[k]
                C = ans[i]
            end
            if length(B ∩ C) == 0
                if sum(B) > sum(C) && length(B) > length(C) continue end
                if allElementLessThan(B,C) == false
                    needTocheck += 1
                end
            end
        end
    end
    println("$needTocheck")
end

main()