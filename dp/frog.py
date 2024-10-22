import math, sys

#DSA05025
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    dp = [0] * 52
    dp[0] = dp[1] = 1
    for i in range(2, n + 1):
        for j in range(1, min(i, 3) + 1):
            dp[i] += dp[i - j]
    print(dp[n])