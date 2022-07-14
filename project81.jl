using DelimitedFiles

#80x80 matrix
matrix = readdlm("project81.txt", ',', Int, '\n')

lines = []
# Converting to something similar in problem 18
# 1st part
for i in 1:80
    line = []
    k = i
    for j in 1:i
        push!(line,matrix[k,j])
        k -= 1
        j += 1
    end
    push!(lines,line)
end

# 2nd part
c = 0
q = 2
iter = 81
while c < 79
    line = []
    j = q
    for k in 80:-1:j
        push!(line,matrix[k,j])
        k -= 1
        j += 1
    end
    for i in 1:(iter-length(line))/2
        pushfirst!(line,999999)
        push!(line,999999)
    end
    push!(lines,line)
    q += 1
    iter += 1
    c += 1
end

# actuall algorithm
for i in 159:-1:2
    for j in 1:length(lines[i])-1
        lines[i-1][j] = min(lines[i][j]+lines[i-1][j],lines[i][j+1]+lines[i-1][j])
    end
end

lines[1][1]
