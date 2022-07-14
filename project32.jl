
function isprime(n)
    flag = true
    if n>1
        for i in 2:n-1
            if n%i==0
                flag = false
                # println(n)
                break
            end
        end
    end
    return flag
end
function main()
    
    # isprime(29)
    cou = 0
    max = 0
    for b in -10000:10000
        for c in -10000:10000
            if (b*b)-(4*c)+163==0
                for i in 0:100
                    d = (i*i)+(b*i)+c
                    if isprime(d) == false
                        break
                    else
                        cou += 1
                    end
                end
                if max < cou
                    max = cou
                end
                cou = 0
            end
        end
    end

    println(max) 
end

@time main()