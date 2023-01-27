

function reduce(seq::Vector) 
    if length(seq) == 1 return seq[1] end

    newSeq::Vector = []
    len = length(seq)
    for i = 2:len
        append!(newSeq,seq[i]-seq[i-1]) 
    end
    return (seq[len] + reduce(newSeq))
end

function main()
    u(n) = 1-n+n^2-n^3+n^4-n^5+n^6-n^7+n^8-n^9+n^10
    n = 1
    ans = 0
    while true
        seq::Vector = []
        for i = 1:n
            append!(seq,u(i))
        end 
        # print(seq)
        term = reduce(seq)
        if u(n+1) == term
            println(ans)
            break
        end
        ans += term
        n += 1
    end
end

main()

