using Combinatorics


triangle(n) = (n*(n+1))/2
square(n) = n^2
pentagonal(n) = (n*(3*n-1))/2
hexagonal(n) = n*(2*n-1)
heptagonal(n) = (n*(5*n-3))/2
octagonal(n) = n*(3*n-2)

func = collect(permutations([triangle.(45:140),square.(32:99),pentagonal.(26:81),hexagonal.(23:70),heptagonal.(21:63),octagonal.(19:58)]))

function istri(k)
    disc = 1+8*k
    disc = sqrt(disc)
    disc = -1 + disc
    disc = disc / 2
    return isinteger(disc)
end

function issq(k)
    return isinteger(sqrt(k)) 
end

function ispent(k)
    disc = 1+24*k
    disc = sqrt(disc)
    disc = 1 + disc
    disc = disc / 6
    return isinteger(disc)
end

function ishex(k)
    disc = 1+8*k
    disc = sqrt(disc)
    disc = 1 + disc
    disc = disc / 4
    return isinteger(disc)
end

function ishept(k)
    disc = 9+40*k
    disc = sqrt(disc)
    disc = 3 + disc
    disc = disc / 10
    return isinteger(disc)
end

function isoct(k)
    disc = 4+12*k
    disc = sqrt(disc)
    disc = 2 + disc
    disc = disc / 6
    return isinteger(disc)
end

which_number(k) = [istri(k), issq(k), ispent(k), ishex(k), ishept(k),isoct(k)]

function ispoly(k)
    ans = [[1,0,0,0,0,0],[0,1,0,0,0,0],[0,0,1,0,0,0],[1,0,0,1,0,0],[0,0,0,0,1,0],[0,0,0,0,0,1]]
   return length(intersect(which_number.(k),ans)) == 6
end

function com(list)
    w = []
    for i in list[1]
        for k in list[2] 
            if (digits(Int64(i%100))) == (digits(Int64(floor(k/100)))) 
                for x in list[3]
                    if (digits(Int64(k%100))) == (digits(Int64(floor(x/100)))) 
                        for a in list[4]
                            if (digits(Int64(x%100))) == (digits(Int64(floor(a/100)))) 
                                for b in list[5]
                                    if (digits(Int64(a%100))) == (digits(Int64(floor(b/100)))) 
                                        for c in list[6]
                                            if (digits(Int64(b%100))) == (digits(Int64(floor(c/100)))) && ((digits(Int64(c%100))) == (digits(Int64(floor(i/100))))) 
                                                push!(w,[i,k,x,a,b,c])
                                                return [sum([i,k,x,a,b,c]),[i,k,x,a,b,c]] 
                                            end
                                        end
                                    end
                                end
                            end
                        end
                    end
                end
            end
        end
    end
    return 0 
end

test = []
for i in func
    if com(i) == 0
        continue
    end
    if ispoly(com(i)[2])
        println(com(i)[1])
        break
    end
end








    

