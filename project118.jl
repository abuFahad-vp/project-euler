
set = Set()

for i in 1:9
    for k in 1:9
        for a in 1:9
            for b in 1:9
                for c in 1:9
                if i+k +a+b+c == 9
                    push!(set,sort([i,k,a,b,c]))
                end
            end
            end
        end
    end
end
println(set)
