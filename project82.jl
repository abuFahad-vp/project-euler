
file = open("adjecency.txt","r")
lines = readlines(file)
dummy = []
for line in lines
    sub = split(line,",")
    tmp = []
    for i in sub
        if(i=="") continue end;
        push!(tmp,parse(Int64,i))
    end
    push!(dummy,tmp)
end

small_matrix = [[131,673,234,103,18],
                [201,96,342,965,150],
                [630,803,746,422,111],
                [537,699,497,121,956],
                [805,732,524,37,331]]

mtx = dummy
size = length(mtx)

function get_column(n)
    c = []
    for i in 1:size
        push!(c,mtx[i][n])
    end
    return c
end

col = size-1
current = get_column(col)
next = get_column(size)

function route(x,y)
    if x > y
        return next[y] + sum(current[y:x])
    else
        return next[y] + sum(current[x:y])
    end
end

function min(x)
    mini = Inf
    for i in x
        if mini > i mini = i end
    end
    return mini
end

function cheapest()
    global col, next, current
    costs = []
    for x in 1:size
        tmp = []
        for y in 1:size
            push!(tmp,route(x,y))
        end
        push!(costs,min(tmp))
    end
    col -= 1
    next = costs
    if col == 0 return end
    current = get_column(col)
end

while col >= 1 cheapest() end
println(min(next))











