
sn = 290797
sn1 = 0
count = 1

for n in 1:19
    sn1 = (sn*sn) % 50515093
    println("$count) $sn1")
    count += 1
    sn = sn1
end