l = Any[]
for a in 1:1000
    for b in 1:1000
        for c in 1:1000
            for i in 1:1000
                if((a+b+c==i) && (a^2+b^2==c^2))
                    println("$i = $a, $b, $c")
                end
            end
        end
    end
end