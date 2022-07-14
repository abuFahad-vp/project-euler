using Primes
function rotate(D); [[D[i:length(D)]; D[1:i-1]] for i in 1:length(D)]; end
function undigits(D); sum(D[k]*10^(k-1) for k=1:length(D)); end
length([p for p in primes(1000000) if all([isprime(undigits(D)) for D in rotate(digits(p))])])

