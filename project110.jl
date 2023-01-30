min = Inf

for i in 1:5
    for y in 0:1:i
        for z in 0:1:y
            ans = Int128(2^i*3^y*5^z*7^2*11*13*17*19*23*29*31*37)
            sol = (2*i+1)*(2*y+1)*(2*z+1)*32805
            if sol > 2*(4*(10^6))
                if min > ans
                    min = ans
                    println("$ans")
                end
            end
        end
    end
end