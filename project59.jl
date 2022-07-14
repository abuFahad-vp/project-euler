using DelimitedFiles
#
# p - T
# m, 
f = open("project59.txt","r")

a = readdlm(f,',')

f = []
s = []
t = []

for i in 3:3:1201
    push!(t,Char(xor(Int('p'),Int(a[i]))))
end

f
s
t

for i in 1:400
    print("$(f[i]s[i]t[i])")
end

# Failed in julia


