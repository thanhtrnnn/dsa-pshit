import math, sys

#DSA05020
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

    dp = [[0] * (m + 1) for _ in range(n + 1)]
    # dp[1][1] = a[0][0]
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i == 1:
                dp[i][j] = dp[i][j - 1] + a[i - 1][j - 1]
            elif j == 1:
                dp[i][j] = dp[i - 1][j] + a[i - 1][j - 1]
            else:
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + a[i - 1][j - 1]

    print(dp[n][m])