import math, sys

#DSA05022
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')
input = lambda: sys.stdin.readline().rstrip("\r\n")
nint = lambda: int(input())
mint = lambda: map(int, input().split())
aint = lambda: list(map(int, input().split()))
###############################################
# genius
t = nint()
for _ in range(t):
    n = nint()
    ins, delt, copy = mint()
    dp = [0] * (n + 1)
    dp[1] = ins
    for i in range(2, n + 1):
        if i % 2 == 0:
            dp[i] = min(dp[i - 1] + ins, dp[i // 2] + copy)
        else:
            # before delete must be copy...!
            dp[i] = min(dp[i - 1] + ins, dp[(i + 1) // 2] + copy + delt)
    print(dp[n])