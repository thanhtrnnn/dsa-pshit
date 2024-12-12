import math, sys

#DSA04024
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
mod = (int)(1e9 + 7)
###############################################
def matrix_product(a, b, n):
    c = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            for k in range(n):
                c[i][j] += a[i][k] * b[k][j]
                c[i][j] %= mod
    return c

def matrix_binpow(a, n, k):
    if k == 1:
        return a
    
    res = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(1 if j == i else 0)
        res.append(row)
    
    while k > 0:
        if k % 2:
            res = matrix_product(res, a, n)
        k //= 2
        a = matrix_product(a, a, n)
    return res

t = nint()
for _ in range(t):
    n, k = mint()
    a = []
    for _ in range(n):
        a.append(aint())

    xum = 0
    res = matrix_binpow(a, n, k)
    for i in range(n):
        xum += res[i][n - 1]
        xum %= mod
    print(xum)