
# numerator and dinominator adjescent to 3/7 is increasing with 3 and 7 respectevely over increasing values
# numerators:- 2,5,8... f = 2, d = 3 fn = 2 + (n-1)*d 
# dinominator:- 5,12,19,26... f = 5, d = 7 fn = 5 + (n-1)*d 

f(n) = 5 + (n-1)*7

l = 1000000
while true
    if isinteger((l+2)/7)
        println(l)
        break
    end
    l -= 1
end


