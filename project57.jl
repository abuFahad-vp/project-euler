nu = big(1)
di = big(2)
c = 0
for i in 1:10
    println("$(nu+di) / $(di)")
    if length(string(nu+di)) > length(string(di))
        c += 1
    end
    temp=big(nu)
    nu=di
    di=di*2+temp
end
c