issquare(x) = sqrt(x) == floor(sqrt(x))

function main()
    i = 1
    while true
        a = i^2
        if iseven(a)
            for k in 2:2:i-2
                x = Int((a+k^2) / 2)
                y = a - x
                for z in 1:y-1
                    if issquare(x+z) && issquare(x-z) && issquare(y-z) && issquare(y+z)
                        println(a, " ",k^2," x = ",x,",y = ",y, ", z = ", z)
                        return
                    end
                end
            end
        end

        if isodd(a)
            for k in 1:2:i-2
                x = Int((a+k^2) / 2)
                y = a - x
                for z in 1:y-1
                    if issquare(x+z) && issquare(x-z) && issquare(y-z) && issquare(y+z)
                        println(a, " ",k^2," x = ",x,",y = ",y, ", z = ", z)
                        return
                    end
                end
            end
        end
        if i % 1000 == 0
            println(i)
        end
        i += 1
    end
end
@time main()