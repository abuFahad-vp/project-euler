@time begin
    
num = 1504170715041707
din = 4503599627370517
r = din-num
sums = num
while num > 0
    if r > num
        n = Int(floor((r-num)/num)+1)
        r = r-num*n
    end
    num -= r
    sums += num
end

println(sums)

end
