
for i in 1:10
    for k in 1:10
        for a in 1:60
            if Int128(floor(((1+sqrt(i))/2)^(a+2)/sqrt(i) - ((1-sqrt(i))/2)^(a+2)/sqrt(i) + cos(π*(a+1)/k) + sin(π*(a+1)/k)/sqrt(k)/2)) == 1148904
                println("found")
            end
        end
    end
end

