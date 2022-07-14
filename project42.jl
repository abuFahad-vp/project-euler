using DelimitedFiles

a = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
function istri(s)
    len = 0
    for i in s
       len += findfirst(isequal(i),a)
    end
    # return len
    # 1/2*n(n+1), n^2 + n = 2*len, n^2+n-2*len = 0
    div = 1
    b = 1
    c = -2*len
    discr = b^2 - 4*div*c
    x1 = ((-b + sqrt(discr))/2div)
    # println("$x1, $x2")
    if(isinteger(x1))
        return true
    end
    return false 
    
end

name = readdlm("project42.txt",',')
c = 0
for i in name
    if(istri(i))
        c += 1
    end
end

c