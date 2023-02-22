
primes = []

# for loop to create a prime number list for numbers 2 - 20000
for n in range (2, 20000 + 1):

    for i in range (2, n):
        if (n % i) == 0:
                break
    else:
        primes.append(n)

sum = 0

n = 0

k = 10**9 # repunit number for which the problem needs to be solved.

count = 0



# loops for the first 40 factors

while count < 40:

    # mod to check if the prime number is a factor and sum up in the result

    if (10 ** k % (9 * primes[n]) == 1):

        sum = sum + primes[n]

        count += 1

    n = n + 1

print(sum)

