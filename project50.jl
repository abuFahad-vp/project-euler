using Primes
# sum = 0
# max = 0
# # guessed the number 5
# # therefore starting prime is 7
# p = 5
# while true
#     p = nextprime(p+1)
#     sum += p
#     println("$p")
#     if sum > 1000000
#         break
#     end
#     if isprime(sum) && sum > max
#         # println(sum)
#         max = sum
#     end
# end

# max

function solutionB(n)
   sum = 0
   max = 0
   for i in primes(n,4000)
        sum += i
        if isprime(sum) && sum > max
            max = sum
        end
        if sum >= 1000000
            return max
        end
    end     
end
m = 0
for i in 1:10
    if solutionB(i) > m && solutionB(i) < 1000000
        m = solutionB(i)
    end
end

m