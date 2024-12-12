import math, sys

#DSA04012
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

t = nint()
for _ in range(t):
    m, n = mint()
    p = aint()
    q = aint()
    res = [0] * (m + n + 1)
    for i in range(m):
        for j in range(n):
            if p[i] != 0 and q[j] != 0:
                res[(i + 1) + (j + 1)] += p[i] * q[j]
    
    print(' '.join(map(str, res[2:])))