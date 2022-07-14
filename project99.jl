
using  DelimitedFiles

n = readdlm("project99.txt",',',Int,'\n')

j = [n[1,1],n[1,2]]
l = 0

for i in 2:1000
    k = [n[i,1],n[i,2]]
    if k[2]*log(k[1]) > j[2]*log(j[1])
        l = i
        j = k
    end
end
l