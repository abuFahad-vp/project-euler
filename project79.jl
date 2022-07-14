using DelimitedFiles


f = open("project79.txt", "r")

logins = readdlm(f,'\n')

first_digits = Set()
second_digits = Set()
third_digits = Set()

for num in logins
    dig = digits(Int(num))
    push!(third_digits,dig[1])
    push!(second_digits,dig[2])
    push!(first_digits,dig[3])
end

println("$(first_digits)\n$(second_digits)\n$(third_digits)")
total_digits = union(first_digits,second_digits,third_digits)
println(total_digits)

function digits_before(x,logins)
    before_digit_x = Set()
    for login in logins
        if x in reverse(digits(Int(login)))
            for digit in reverse(digits(Int(login)))
                if digit == x
                    break
                else
                    push!(before_digit_x,digit)
                end
            end
        end
    end
    return Tuple(before_digit_x)
end

dic = Dict()
for i in total_digits
    dic[i] = digits_before(i,logins)
end

dic
for i in 1:8
    println("$(index[i]) -> $(all[i])")
end
