    
using SimpleWeightedGraphs

include("project107_1.jl")

ori = 0
for i in matrix
    ori += i
end

ori = ori/2

g = SimpleWeightedGraph(matrix)
mst = kruskal_mst(g)
ans = 0

for i in mst
    ans += i.weight
end

println(ori-ans)