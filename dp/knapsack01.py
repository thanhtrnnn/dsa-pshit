import math, sys

#DSA05027, DSAKT055
sys.stdin = open("E:/OneDrive - ptit.edu.vn/pro/dsa/input.txt", mode = 'r')
sys.stdout = open("E:/OneDrive - ptit.edu.vn/pro/dsa/output.txt", mode = 'w')

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    weight = list(map(int, input().split()))
    value = list(map(int, input().split()))
    # TLE both approaches
    # dp = [[0] * (m + 1) for z in range(n + 1)]
    # for i in range(1, n + 1):
    #     for j in range(1, m + 1):
    #         if weight[i - 1] <= j:
    #             # Max value by either including or excluding the current item
    #             dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + value[i - 1])
    #         else:
    #             # Current item can't be included because it's too heavy
    #             dp[i][j] = dp[i - 1][j]
    
    # print(dp[n][m])
    dp = [0] * (m + 1)
    
    for i in range(n):
        # Traverse in reverse to avoid overwriting results from this iteration
        for j in range(m, weight[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i])
    
    print(dp[m])


    