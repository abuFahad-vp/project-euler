
using Combinatorics

a = [x for x in 1:15]
file = open("project121.txt","w")

for i in 1:7
    for x in collect(combinations(a,i))
        for z in x
            if x[lastindex(x)] == z
                print(z)
                write(file,"$z")
            else
                print(z," ")
                write(file,"$z ")
            end
        end
        println()
        write(file,"\n")
    end
end
close(file)