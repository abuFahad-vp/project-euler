
using Memoize

function F(θ::BigFloat)
    @memoize b(n) = n == 1 ? θ : a(n-1) * (b(n-1) - a(n-1) + 1)
    a(n) = floor(Int, b(n))
    parse(BigFloat, join(string.([a(1), ".", map(a, 2:15)...])))
end

F(BigFloat(2.22))
