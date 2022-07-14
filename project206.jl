
# a b c d e f g h i j
# 1_2_3_4_5_6_7_8_9_0
a = 1
b = 0
c = 1
d = 0
e = 1
f = nothing
g = 1

num = ["j","i","h","g","f","e","d","c","b","a"]
eq = []
for i in num
    tmp = []
    for k in num
        push!(tmp,"$i$k")
    end
    push!(eq,tmp)
end

n = 0
for i in eq
    println(i)
    for k in 0:n
        print("      ")
    end
    n += 1
end

for g in 0:1:9
    for h in 0:1:9
        if (6*g) + h^2 == 7
            println("$g $h")
        end
    end
end

