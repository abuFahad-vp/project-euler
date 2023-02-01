
darts = []
dartsValue = Dict()
doubles = []

for i in 1:20
    S = "S$i"
    D = "D$i"
    T = "T$i"
    push!(darts,S,D,T)
    push!(doubles,D)
    dartsValue[S] = i*1
    dartsValue[D] = i*2
    dartsValue[T] = i*3
end

push!(darts,"B25","B50","0")
push!(doubles,"B50")
dartsValue["B25"] = 25
dartsValue["B50"] = 50
dartsValue["0"] = 0

ans = Set()

for i in 1:99
    for x in darts
        for y in darts
            for d in doubles
                b1 = dartsValue[x]
                b2 = dartsValue[y]
                b3 = dartsValue[d]
                if b1+b2+b3 == i
                    tmp = []
                    append!(tmp, sort(["$x","$y"]))
                    push!(tmp,"$d")
                    push!(ans,tmp)
                end
            end
        end
    end
end

println(length(ans))