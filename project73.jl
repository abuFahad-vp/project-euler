# di(k,n) = 3*k + 2*n
# nu(k,n) = k + n
# c = 0
# for k in 1:12000
#     if di(k,1) > 12000
#         break
#     end
#     for n in 1:12000
#         D = di(k,n)
#         if D > 12000
#             break
#         end
#         N = nu(k,n)
#         if gcd(N,D) == 1
#             c += 1
#         end
#     end
# end

# c

limit = 12000
a = 1
b = 3
c = 4000
d = 11999

result = 0

while (c==1 && d==2) != true
    result += 1
    k = (limit+b) / d
    e = k * c - a
    f = k * d - b
    a = c
    b = d
    c = e
    d = f
end


result






