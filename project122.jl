
dict = Dict()
dict[1] = 0

index = 1
array = [[1]]
while(true)
    if index > 10 break end
    arrayIndex = length(array)
    prev = 0
    for i in index:arrayIndex
        if prev == i break end
        lastElem = array[i][lastindex(array[i])] # 1
        # println("lastElem = $lastElem")
        lenX = length(array[i])
        # println("array = $array")
        # println("index = $i")
        # println("array[i] = $(array[i])")
        for x in 1:lenX
            temp = copy(array[i]) # [1]
            term = array[i][x] + lastElem
            push!(temp,term)
            push!(array,temp)
            try
                if dict[term] > index
                    dict[term] = index
                end
            catch e
                if isa(e,KeyError)
                    dict[term] = index
                end
            end
        end
        prev = i
    end
    index += 1
end

ans = 0
for i in 1:200
    ans += dict[i]
end

println(ans)