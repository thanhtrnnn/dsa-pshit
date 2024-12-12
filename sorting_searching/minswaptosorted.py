import math, sys

#DSA06003
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

t = nint()
for _ in range(t):
    n = nint()
    a = aint()
    res = 0
    for i in range(n - 1):
        minbuddy, minidx = 1e10, 0
        for j in range(i, n):
            if a[j] < minbuddy:
                minbuddy = a[j]
                minidx = j
        if minidx != i:
            a[i], a[minidx] = a[minidx], a[i]
            res += 1
    print(res)
