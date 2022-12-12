
sum = big(0)
sum1 = big(1)
sum2 = big(1)
99987
n = 3

function ispen(num)
    array = [1,2,3,4,5,6,7,8,9]
    last = num%1000000000
    d = sort(digits(last))
    len = floor(log10(num))+1
    if len <= 9 return false end
    l = d[len-8:len]
    d = d[1:9]
    if array == d && array == sort(l) return true end
    return false
end

while(true)
    global n
    global sum
    global sum1
    global sum2
    sum = sum1+sum2
    if(n==32468)
        println("finish = $n")
        println("$sum")
        break
    end
    println("$n")
    sum2 = sum1
    sum1 = sum
    n += 1
end


