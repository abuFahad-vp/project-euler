

Layer(x,y,z,n) = 2*(x*y+y*z+z*x)+4*(x+y+z+n-2)*(n-1)

dict = Dict()
N = 1000*20

for a in 1:10000
    if Layer(a,a,a,1) > N break end
    for b in a:10000
        if Layer(a,b,b,1) > N break end
        for c in b:10000
            if Layer(a,b,c,1) > N break end
            for l in 1:10000
                if Layer(a,b,c,l) > N break end
                cubes = Layer(a,b,c,l)
                try
                    dict[cubes] += 1
                catch e
                    if isa(e,KeyError)
                        dict[cubes] = 1
                    end
                end
            end
        end
    end
end

minis = Inf

for x in keys(dict)
    if dict[x] == 1000
        if minis > x
            minis = x
        end
    end
end

println(minis)