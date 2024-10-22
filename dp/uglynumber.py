import math, sys

#DSA05016
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n = int(input())
    dp = [0] * (n + 1)
    dp[1] = 1
    two, three, five = 1, 1, 1 # all point to dp[1 = 1
    for i in range(2, n + 1):
        # dp[2] = min(2, 3, 5)
        # dp[3] = min(4, 3, 5)
        # dp[4] = min(4, 6, 5)
        # dp[5] = min(6, 6, 5)
        # dp[6] = min(6, 6, 10)
        # dp[7] = min(8, 9, 10)
        # dp[8] = min(10, 9, 10)
        # dp[9] = min(10, 12, 10)
        dp[i] = min(dp[two] * 2, dp[three] * 3, dp[five] * 5)

        # dp[2] == dp[1] * 2
        # dp[4] == dp[2] * 2
        # dp[6] == dp[3] * 2
        # dp[7] == dp[4] * 2
        # dp[9] == dp[5] * 2
        if dp[i] == dp[two] * 2:
            # two = 2, 3, 4, 5, 6
            two += 1
        
        # dp[3] == dp[1] * 3
        # dp[6] == dp[2] * 3
        # dp[9] == dp[3] * 3
        if dp[i] == dp[three] * 3:
            # three = 2, 3, 4
            three += 1

        # dp[5] == dp[1] * 5
        # dp[9] == dp[2] * 5
        if dp[i] == dp[five] * 5:
            # five = 2, 3
            five += 1
    print(dp[n])