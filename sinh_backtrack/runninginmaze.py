import math, sys

#DSA02012
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

t = nint()
for _ in range(t):
    n, m = mint()
    a = []
    for _ in range(n):
        a.append(aint())
    print(math.comb(n + m - 2, n - 1))
