


modulus = 1000000007

function power(x, y, p)
    # Initialize result
    res = 1
    while (y > 0)
        # If y is odd, multiply x with result
        if ((y & 1) != 0)
            res = res * x
        end
        # y must be even now
        y = y >> 1  # y = y/2
        x = x * x  # Change x to x^2
        end
    return res % p
end
 
 
sn(n) = (((n%9+1)%modulus)*(power(10,Int(floor(n/9)),modulus)) - 1) % modulus
Sn(n) = ((6 * power(10,n,modulus))%modulus - (9*(n%modulus))%modulus - 6) % modulus

sn(19)
Sn(2)

f1 = 0
f2 = 1
fn = 0


for i = 2:90
    fn = f1 + f2    
    println(fn," ",Sn_nn(Int(floor(fn/9))))
    f1 = f2
    f2 = fn
end

