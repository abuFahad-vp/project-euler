
m,n = 3,7

ways = [1]*m + [0]*(n-m+1)
print(ways)
for k in range(m,n+1):
    print(ways[:k-m])
    print(ways[k-1])
    ways[k] = ways[k-1] + sum(ways[:k-m]) + 1
print(ways[n])