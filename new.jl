
setprecision(1000)

a = BigFloat(2) ^ (1/2)

a = a-1

for i in 1:100
    global a
    a = a*10
end
a = floor(a)
println(digits(a))

