import math, sys

#DSA05008
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    dp = [False] * 50000
    dp[0] = True
    for i in range(n):
        for j in range(s, a[i] - 1, -1):
            # dp[j] |= dp[j - a[i]]
            if dp[j - a[i]] == 1:
                dp[j] = True

    print('YES' if dp[s] else 'NO')
