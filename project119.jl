
count = 1
i = 81
list = []
for b in 1:100
    for p in 1:11
        a = b^p
        s = sum(digits(a))
        if s == b && a > 9
            push!(list,a)
        end
    end
end

println(sort(list)[30])
