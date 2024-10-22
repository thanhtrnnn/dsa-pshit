import math, sys

#DSA05014
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################

def nthcatalan(n):
    dp = [0] * (n + 1)
    dp[0] = 1
    for i in range(1, n + 1):
        for j in range(i // 2):
            dp[i] += dp[j] * dp[i - j - 1]
        if i > 1:
            dp[i] *= 2
        if i % 2:
            dp[i] += dp[i // 2] ** 2
    print(dp[n])

t = nint()
for _ in range(t):
    n = nint()
    nthcatalan(n)
