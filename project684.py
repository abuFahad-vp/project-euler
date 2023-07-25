import math
modulus = 1000000007

# Iterative Function to calculate (x^y)%p in O(log y)
def power(x, y, p):

	# Initialize result
	res = 1

	while (y > 0):

		# If y is odd, multiply x with result
		if ((y & 1) != 0):
			res = res * x

		# y must be even now
		y = y >> 1 # y = y/2
		x = x * x # Change x to x^2

	return res % p

def sn(n):
    return (((n%9+1)%modulus)*(power(10,math.floor(n/9),modulus)) - 1) % modulus